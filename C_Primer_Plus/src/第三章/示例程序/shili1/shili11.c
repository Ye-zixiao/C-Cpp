/*---------演示参数错误的情况（参数数量前后不匹配、参数数据类型前后不匹配）------*/
#include<stdio.h>
int main(void)
{
    int n=4;
    int m=5;
    float f=7.0f;
    float g=8.0f;

    printf("%d\n",n,m);
    printf("%d %d %d\n",n,m);
    printf("%d %d\n",f,g);

    return 0;
}
