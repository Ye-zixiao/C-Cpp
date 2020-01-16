#include<stdio.h>
int main(void)
{
    int i,j,list[10];

    for(i=0;i<=9;i++)               //注意数组list[10]是从0到9进行下标区别的
    {
        list[i]=2*i+3;
        for(j=0;j<=i;j++)
            printf(" %d",list[j]);
        printf("\n");
    }

    return 0;
}
