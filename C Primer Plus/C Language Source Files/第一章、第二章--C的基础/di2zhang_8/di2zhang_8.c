/*-------使用两个嵌套函数-------*/
//打印出one、two、three，其中打印two使用到了两次函数的嵌套
#include <stdio.h>
void one_three(void);
void two(void);

int main(void)
{
    printf("starting now:\n");
    one_three();
    printf("done!\n");

    return 0;
}

void one_three(void)
{
    printf("one\n");
    two();
    printf("three\n");
}

void two(void)
{
    printf("two\n");
}
