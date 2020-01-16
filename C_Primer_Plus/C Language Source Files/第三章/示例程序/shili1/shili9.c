/*----------演示舍入误差---------*/
#include<stdio.h>
int main(void)
{
    float a,b;
    double c;

    b=2.0e20+1.0;
    a=b-2.0e20;
    c=1.6e29+1.6e27;
    printf("%f\n",a);//这是由于计算机缺乏足够的小数位来完成正确的运算
    printf("%e\n",c);//正确
    return 0;

}
