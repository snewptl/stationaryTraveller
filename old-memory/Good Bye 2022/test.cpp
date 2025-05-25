int64_t
spdk_file_read(struct spdk_file *file, struct spdk_fs_thread_ctx *ctx,
               void *payload, uint64_t offset, uint64_t length)
{
    struct spdk_fs_channel *channel = (struct spdk_fs_channel *)ctx;
    uint64_t final_offset, final_length;
    uint32_t sub_reads = 0;
    struct cache_buffer *buf;
    uint64_t read_len;
    struct rw_from_file_arg arg = {};
    // 获取文件自旋锁
    pthread_spin_lock(&file->lock);
    BLOBFS_TRACE_RW(file, "offset=%ju length=%ju\n", offset, length);
    /*BLOBFS_TRACE_RW调用SPDK_DEBUGLOG*/
    file->open_for_writing = false; /*struct spdk_file是“file”的内存数据结构，
    open_for_writing可以认为是写锁*/
    // 读取长度为0或读取偏移量（头部）越界
    if (length == 0 || offset >= file->append_pos)
    {
        pthread_spin_unlock(&file->lock);
        return 0;
    }
    // 读取部分的尾部越界
    if (offset + length > file->append_pos)
    {
        length = file->append_pos - offset;
    }
    if (offset != file->next_seq_offset)
    {
        file->seq_byte_count = 0;
    }
    file->seq_byte_count += length;
    file->next_seq_offset = offset + length;
    // 判断读取数据是否大于CACHE_READAHEAD_THRESHOLD(默认情况下，该值为128KB)
    if (file->seq_byte_count >= CACHE_READAHEAD_THRESHOLD)
    {
        // 触发异步预读操作，提前将一部分数据读取到内存中
        check_readahead(file, offset, channel); /* check_readahead调用
        alloc_fs_request、cache_insert_buffer和send_request。alloc_fs_request调用
        alloc_fs_request_with_iov，alloc_fs_request_with_iov调用TAILQ_FIRST和
        memset来
        申请拷贝；cache_insert_buffer调用spdk_mempool_get、tree_insert_buffer，
        spdk_mempool_get调用rte_mempool_get获取内存池中的一个内存单元；通过文件系统的数
        据结构
        中的send_request发送读取数据申请*/
        check_readahead(file, offset + CACHE_BUFFER_SIZE, channel);
    }
    arg.channel = channel;
    arg.rwerrno = 0;
    final_length = 0;
    final_offset = offset + length;
    // 对读取的数据进行切分，使得每次读取数据不超过buffer node的大小，即
    CACHE_BUFFER_SIZE的值。
    while (offset < final_offset)
    {
        int ret = 0;
        length = NEXT_CACHE_BUFFER_OFFSET(offset) - offset;
        // 判断读取长度是否越界
        if (length > (final_offset - offset))
        {
            length = final_offset - offset;
        }
        // 根据当前offset的值在cache tree中查询对应的buffer node
        buf = tree_find_filled_buffer(file->tree, offset); /*
        tree_find_filled_buffer调用tree_find_buffer寻找cache tree中的某段偏移*/
        if (buf == NULL)
        { // buffer node节点为空，即未找到对应的buffer node节
            点，即说明缓存未命中
            // 获取文件自旋锁
            pthread_spin_unlock(&file->lock);
            // 通过Blobstore提供的异步读取直接从存储设备读取
            ret = __send_rw_from_file(file, payload, offset, length, true,
                                      &arg); /*__send_rw_from_file调用
                                      alloc_fs_request_with_iov、send_request、
                                      __rw_from_file，alloc_fs_request_with_iov
                                      调用TAILQ_FIRST和memset、calloc来申请
                                      拷贝，__rw_from_file调用
                                      spdk_file_read_async读取*/
            // 释放文件自旋锁
            pthread_spin_lock(&file->lock);
            if (ret == 0)
            {
                sub_reads++;
            }
        }
        else
        { // 可以找到对应的buffer node节点，即说明缓存命中
            read_len = length;
            if ((offset + length) > (buf->offset + buf->bytes_filled))
            {
                read_len = buf->offset + buf->bytes_filled - offset;
            }
            BLOBFS_TRACE(file, "read %p offset=%ju length=%ju\n", payload,
                         offset, read_len);
            // 将其缓存的文件数据执行memcpy拷贝到payload中
            memcpy(payload, &buf->buf[offset - buf->offset], read_len);
            if ((offset + read_len) % CACHE_BUFFER_SIZE == 0)
            {
                tree_remove_buffer(file->tree, buf); /*tree_remove_buffer调用
                cache_buffer_free和递归自身来释放cache tree某个节点以及其子结点的空间*/
                if (file->tree->present_mask == 0)
                {
                    spdk_thread_send_msg(g_cache_pool_thread,
                                         _remove_file_from_cache_pool, file);
                }
            }
        }
        // 更新
        if (ret == 0)
        {
            final_length += length;
        }
        else
        {
            arg.rwerrno = ret;
            break;
        }
        payload += length;
        offset += length;
    }
    pthread_spin_unlock(&file->lock);
    while (sub_reads > 0)
    {
        sem_wait(&channel->sem); // 利用sem信号量进行同步，直到所有的读取完成
        sub_reads--;
    }
    if (arg.rwerrno == 0)
    {
        return final_length;
    }
    else
    {
        return arg.rwerrno;
    }
}