#include<stdio.h>
double power(double x,int exp);

int main(void)
{
    double num1,num2;

    printf("Enter two numbers for this program\n");
    printf("(enter q to quit)\n");
    while(scanf("%lf %lf",&num1,&num2)==2)
    {
        printf("%0.2f to the power %0.2f is %0.2f\n",num1,num2,power(num1,num2));
        printf("Keep entering for this program\n");
        printf("(enter q to quit)\n");
    }
    printf("Done\n");

    return 0;
}

double power(double x,int exp)
{
    double ans=1;

    if(exp==0)
    {
        if(x==0)
            printf("0 to the power 0 is undefined,but see 1 as the answer\n");
        ans=1;
    }                                   /*ע�⣺else if ����ǵ�һ��if else�����else�ķ�֧������if��ķ�֧
                                            ���ԣ�if����
                                                    if����    ����д��else if
                                                   else
                                                       if����  �����if���Ա��else if
                                                       else                                                     */
    else if(exp>0)//������
    {
        int i;
        for(i=1;i<=exp;i++)
            ans*=x;
    }
    else//������
    {
        int i;
        for(i=1;i<=-exp;i++)
            ans*=1/x;
    }

    return ans;
}
