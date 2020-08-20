//ÆÕÍ¨º¯Êı·¨
#include<stdio.h>
double change(double,double);

int main(void)
{
    double x=1.5,y=6.3;

    printf("Originally,x=%0.2f and y=%0.2f\n",x,y);
    x=y=change(x,y);
    printf("Now,x=%0.2f and y=%0.2f\n",x,y);

    return 0;
}

double change(double x,double y)
{
    return x>y?x:y;
}
