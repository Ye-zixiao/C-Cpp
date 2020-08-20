/*--------输出各个国家中的名字----------*/
/*--------对应第2章的5-------------------*/
#include<stdio.h>
void br(void);
void ic(void);
int main(void)
{
    br();
    printf(", ");
    ic();
    printf("\n");

    ic();
    printf("\n");
    br();

    return 0;
}

void br(void)
{
    printf("Brazil, Russia");
}

void  ic(void)
{
    printf("India, China");
}
