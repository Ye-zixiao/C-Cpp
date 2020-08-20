#include<stdio.h>
int main(void)
{
    int strlen(const char *str);            //注意这个程序在VS2019中并没有什么实际的运行
    int size;
    size=strlen("I love you!");
    printf("strlen of this is %d\n",size);

    return 0;
}

int strlen(const char *str)
{
    int ct=0;
    while(*str!='\0')
        ct++;

    return ct;
}
