#include<stdio.h>
double result(double x,double y);
int main(void)
{
    double num1,num2;

    printf("Please enter two numbers for this program.\n");
    while(scanf("%lf %lf",&num1,&num2)==2)
    {
        printf("The result is %.6f.\n",result(num1,num2));
        printf("Keep enter the numbers.\n");
        printf("Enter the q to quit this program.\n");
    }

    return 0;
}


double result(double x,double y)
{
    return (x-y)/(x*y);
}
