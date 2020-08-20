#include<stdio.h>
void large_of(double *x,double *y);

int main(void)
{
    double num1,num2;

    printf("Enter two floatings for this program\n");
    printf("(enter q to quit this praogram)\n");
    while(scanf("%lf %lf",&num1,&num2)==2)
    {
        printf("Originally, x=%0.2f and y=%0.2f\n",num1,num2);
        large_of(&num1,&num2);
        printf("Now, x=%0.2f and y=%0.2f\n",num1,num2);
        printf("Please enter another two numbers for this program\n");
    }
    printf("Done\n");

    return 0;
}

void large_of(double *x,double *y)
{
    *x=*y=*x>*y?*x:*y;
}
