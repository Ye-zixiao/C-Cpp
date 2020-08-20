/*-----5.14累加法----*/
#include<stdio.h>
int main(void)
{
    const int size=8;
    int i;
    double num1[size],num2[size];

    printf("Enter %d numbers for this program:\n",size);
    for(i=0;i<size;i++)
    {
        printf("#%d:  ",i+1);
        scanf("%lf",&num1[i]);
    }

    num2[0]=num1[0];
    for(i=1;i<=7;i++)
        num2[i]=num2[i-1]+num1[i];  //在前一项的基础上再加

    for(i=0;i<size;i++)
        printf("%6.2f",num1[i]);
    printf("\n");
    for(i=0;i<size;i++)
        printf("%6.2f",num2[i]);
    printf("\n");

    return 0;
}
