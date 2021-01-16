#include<stdio.h>
int main(void)
{
    char ch;
    char ch1;

    while((ch=getchar())!=EOF)
    {
        putchar(ch);
        while((ch1=getchar())!='\n')      //用于吃掉第一个后面的字符
            continue;
        if(ch1=='\n')
            printf("I get it\n");
    }
    putchar('\n');

    return 0;
}
