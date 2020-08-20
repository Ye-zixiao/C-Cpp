#include<stdio.h>
int main(void)
{
    char ch[256];
    int i=-1;

    do
    {
        i++;
        scanf("%c",&ch[i]);
    }
    while(ch[i]!='\n');//记住每一个逗号表达式的值等于右边表达式的值

    for(;i>=0;i--)              //这种计数方法类似于从低到高（增序）然后从高到低（降序）打印，类似于第6章的第5题
        printf("%c",ch[i]);
    printf("\n");

    return 0;
}
