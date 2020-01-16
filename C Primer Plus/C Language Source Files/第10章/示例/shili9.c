#include<stdio.h>
#define SIZE 10
int aump(int *,int *);

int main(void)
{
    int marbles[SIZE]={20,10,5,39,4,16,19,26,31,20};
    long ans;

    ans=sump(marbles,marbles+SIZE);
    printf("The total number of marbles is %ld.\n",ans);

    return 0;
}

int sump(int *start,int *end)
{
    int total=0;

    while(start<end)
    {
        total+=*start;          //指针变量所指向的数组元素的值相加
        start++;                //指针变量自加1
    }

    return total;
}
