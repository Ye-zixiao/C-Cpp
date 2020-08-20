/*-------打印多个smile--------*/
//第2章的7题
#include<stdio.h>
void sm(void);
void huanhang(void);
int main(void)
{
    int i,j;
    for(i=3;i>0;i--)            //打印出三个smile
    {
        sm();
    }
    huanhang();
    //printf("\n");

    for(j=2;j>0;j--)            //打印出2个smile
    {
        sm();
    }
    huanhang();
    //printf("\n");

    sm();                         //打印出一个smile
    huanhang();
    //printf("\n");

    return 0;
}

void sm(void)
{
    printf("Smile!");
}

void huanhang(void)
{
    printf("\n");
}
