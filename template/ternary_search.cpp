int ternary_search_int(int l, int r) {
    while (r - l + 1 > 3) {  // 当区间足够小时退出
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        
        if (f(m1) < f(m2)) {
            l = m1 + 1;
        } else {
            r = m2;
        }
    }
    
    // 在小范围内线性搜索
    for (int i = l; i <= r; ++i) {
        max_val = max(max_val, f(i));
    }
    return max_val;
}