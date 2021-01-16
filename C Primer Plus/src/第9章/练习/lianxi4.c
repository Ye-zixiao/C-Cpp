#include<stdio.h>
double average(double,double);

int main(void)
{
    double x=1.5;
    double y=2.6;
    double temp;

    printf("x=%0.2f and y=%0.2f\n",x,y);
    temp=average(x,y);
    printf("The average of thid two numbers is %0.2f\n",temp);

    return 0;
}

double average(double x,double y)
{
    double temp;
    temp=1/x+1/y;

    return 2/temp;
}
