#include<stdio.h>
double power(double n,int p);
int main(void)
{
    double x,result;  //xΪ������xpowΪ��ֵ
    int exp;        //ָ��

    printf("Enter a number and a positive power");
    printf(" to which\nthe number will be raised.Enter q");
    printf(" to quit.\n");

    while(scanf("%lf%d",&x,&exp)==2)            //scanf()�������ص�������
    {
        result=power(x,exp);
        printf("%.3g to the power %d is %.5g\n",x,exp,result);
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoy this power trip.\n");

    return 0;
}

double power(double n,int p)
{
    double pow=1;
    int i=1;

    for(;i<=p;i++)
        pow*=n;

    return pow;
}
