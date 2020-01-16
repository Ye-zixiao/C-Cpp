#include<stdio.h>
#define SIZE 4

int main(void)
{
    short dates[SIZE];
    short *pti;
    short index;
    short bills[SIZE];
    short *ptf;

    pti=dates;                      //将数组dates的地址给pti
    ptf=bills;                      //将数组bills的地址给ptf
    printf("%23s %15s\n","short","double");
    for(index=0;index<SIZE;index++)
        printf("pointers+%d:    %10p     %10p\n",index,pti+index,ptf+index);
                                                        //字节+2  字节+2
    return 0;
}
