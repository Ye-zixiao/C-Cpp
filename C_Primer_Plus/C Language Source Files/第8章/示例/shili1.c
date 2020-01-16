#include<stdio.h>
int main(void)
{
    char ch;

    while((ch=getchar())!=EOF)//使用时对文本先回车然后按Ctrl+Z然后再回车
        putchar(ch);
    printf("\n");

    return 0;
}
