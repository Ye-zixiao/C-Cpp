#include<stdio.h>
#include<float.h>
int main(void)
{
    float x=1.0/3.0;
    double y=1.0/3.0;

    printf("%-18.6g %-18.6g\n",x,y);
    printf("%-18.12g %-18.12g\n",x,y);
    printf("%.16g %.16g\n",x,y);
    printf("%-18d %-18d\n",FLT_DIG,DBL_DIG);

    return 0;
}
