#include<stdio.h>
#include<ctype.h>
int main(void)
{
    char ch;

    while((ch=getchar())!='\n')
    {
        if(isalpha(ch))//isalpha返回的是一个非零值，不一定是1
            putchar(ch+1);
        else
            putchar(ch);
    }
    putchar(ch);

    return 0;
}
