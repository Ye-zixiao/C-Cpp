/*-------以两种方式显示浮点型的值--------*/
#include<stdio.h>
int main()
{
    float aboat=32000.0;
    double abet=2.14e9;
    long double dip=5.32e-5;

    printf("%f can be written %e\n",aboat,aboat);                   //将浮点数分别打印成十进制数和指数形式
    printf("And it's %a in hex ,powers of 2 notation\n",aboat);      //将浮点数打印成十六进制数形式
    printf("%f can be written %e\n",abet,abet);                     //将双精度浮点数打印成十进制数形式
    printf("%Lf can be written %Le\n",dip,dip);                     /*将长双精度浮点数打印成指数形式
                                                                        经检验这个long double 确实不能正常使用
                                                                        但是在VS2019上面是可以正常运行的，估计是Code::Blocks编译器的原因*/

    return 0;
}

/*
%f--------用十进制数表示浮点数
%e--------用指数形式表示浮点数
%a--------用十六进制数表示浮点数
以上都是通用于float和double

而针对长双精度long double需要在f、e、a前面加上L（大写有利于分辨）
*/
