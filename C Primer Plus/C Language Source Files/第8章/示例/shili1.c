#include<stdio.h>
int main(void)
{
    char ch;

    while((ch=getchar())!=EOF)//ʹ��ʱ���ı��Ȼس�Ȼ��Ctrl+ZȻ���ٻس�
        putchar(ch);
    printf("\n");

    return 0;
}
