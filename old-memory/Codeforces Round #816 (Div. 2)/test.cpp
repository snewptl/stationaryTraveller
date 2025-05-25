#include <stdio.h>
#include <Windows.h>

//将一个十进制数转换为二进制
void  trans_binary(unsigned int  val)
{
    int a[32];
    int i = 0;
    for(i=0;i<=31;i++)
    { 
        a[i] = val % 2;
        val /= 2;
    }
    //倒序输出，每输出8位，输出一个空格
    for (int j = 31,k = 1; j >= 0; j--,k++)
    {
        printf("%d", a[j]);
        if (k % 8 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}

//循环左移

void left_move(unsigned val, int n)
{
    unsigned int z;
    printf("需要移位的二进制序列为：\n");
    trans_binary(val);
    z = (val >> (32 - n) | (val << n));
    printf("移位后：\n");
    trans_binary(z);
}

void right_move(unsigned val, int n)
{
    unsigned int z;
    printf("需要移位的二进制序列为：\n");
    trans_binary(val);
    z =  (val << (32 - n) | (val >> n));
    printf("移位后：\n");
    trans_binary(z);
}

int main()
{
    int num = 0;
    int n = 0;
    int select = 0;
    printf("请输入要移位的数和移动位数：\n");
    scanf("%d%d", &num, &n);
    printf("请输入选择：(-1-:左移 -2-:右移 -0-:退出):\n");
    scanf("%d", &select);
    switch (select)
    {
    case 1:left_move(num, n);
        printf("\n");
        break;
    case 2:right_move(num, n);
        break;
    case 0:exit(0);
        break;
    default:
        printf("输入有误！\n");
        break;
    }
    system("pause");
    return 0;
}