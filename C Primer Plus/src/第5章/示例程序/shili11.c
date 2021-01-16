#include<stdio.h>
int main(void)
{
    int a=1,b=1;
    int a_post,pre_b;

    a_post=a++;           //先进行++前的表达式，然后自增
    pre_b=++b;            //先自增，再进行表达式
    printf("%1d %5d %5d %5d \n",a,a_post,b,pre_b);

    return 0;
}
