#include<stdio.h>
#define SIZE 8
int power(int n);
int main(void)
{
    int num[SIZE];
    int i=0,j=0;

    for(;i<SIZE;i++)
        num[i]=power(i);
    do
    {
        printf("%5d\n",num[j]);
        j++;
    }
    while(j<SIZE);
    printf("\n");

    return 0;
}

int power(int n)
{
    int power,i;
    for(i=1,power=1;i<=n;i++)
        power*=2;
    return power;
}
