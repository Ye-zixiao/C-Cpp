#include<stdio.h>

int main(void)
{
    char ch[256];
    int i=0;

    printf("Enter the inputs:\n");
    do
    {
        scanf("%c",&ch[i]);
    }
    while(ch[i]!='\n',i++);/*这里有一个错误的使用方法就是逗号表达
                                式的值是等于右侧表达式的值，而表达式
                                这个scanf等于时就会把i++作为while的判
                                断值，而i++显然非零是真*/
                                //所以这种用法不合适，这个程序也不会正确的运行！
    for(i--;i>=0;i--)
        printf("%c",ch[i]);
    printf("\n");

    return 0;
}
