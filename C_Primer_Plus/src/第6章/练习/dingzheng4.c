#include<stdio.h>
int main(void)
{
    const int size=8;
    double num1[size],num2[size],sum;
    int i,j;

    printf("Enter %d numberss for this program\n",size);
    for(i=0;i<size;i++)                     //不断输入数据同时通过累加的方式将前几个数据赋给相应的num2
    {
        printf("#%d:  ",i+1);
        scanf("%lf",&num1[i]);
        for(j=0,sum=0;j<=i;j++)
            sum+=num1[j];
        num2[i]=sum;
    }

    for(i=0;i<size;i++)
        printf("%6.2f",num1[i]);
    printf("\n");
    for(i=0;i<size;i++)
        printf("%6.2f",num2[i]);
    printf("\n");

    return 0;
}
