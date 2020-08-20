#include<stdio.h>
int fibo(int n);

int main(void)
{
    int n;

    printf("Please enter the serial_number of Fibonacci:\n");
    while(scanf("%d",&n)==1)
    {
        printf("The Fibonacci(%d)=%d\n",n,fibo(n));
        printf("Enter next number for the series\n");
    }
    putchar('\n');

    return 0;
}

int fibo(int n)
{
    int ans=1;
    int fn_2=1,fn_1=1;
    int i;

    for(i=1;i<=n-2;i++)
    {
        ans=fn_2+fn_1;          //쳲���������ǰ����֮��
        fn_2=fn_1;              //Ϊ��һ��ʹ����׼��
        fn_1=ans;
    }

    return ans;
}
