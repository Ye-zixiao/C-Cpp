#include<stdio.h>
#include<ctype.h>
int main(void)
{
    char ch;

    while((ch=getchar())!='\n')
    {
        if(isalpha(ch))//isalpha���ص���һ������ֵ����һ����1
            putchar(ch+1);
        else
            putchar(ch);
    }
    putchar(ch);

    return 0;
}
