/*------演示一些浮点运算中的舍入误差-------*/
#include<stdio.h>
int main(void)
//整形上溢出
/*{
    unsigned short a;
    short b;
    a=65535;
    b=32767;
    printf("%hu %hu %hu\n%hd %hd %hd\n",a,a+1,a+2,b,b+1,b+2);

    return 0;
}*/

//浮点数上溢出
/*{
    float a;
    a=3.4e38*100.0f;

    printf("%e\n",a);

    return 0;
}*/

//浮点数下溢出
{
	float a = 1.17549e-38;
	printf("%e\n", a/2);
	return 0;
}
