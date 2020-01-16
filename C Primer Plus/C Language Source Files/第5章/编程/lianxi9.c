/*-------将华氏温度转化为摄氏温度和开氏温度-----*/
#include<stdio.h>
void temper(double x);
int main(void)
{
    double temp;
    int ret_scanf;

    printf("This program is using for calculatering the\n");
    printf(" S's temperatures and K's temperatures.\n");
    printf("Enter the Wallet temperatures that you want:");

    ret_scanf=scanf("%lf",&temp);                           //不断检测输入的字符是否是数字字符，若是则进入while循环
    while(ret_scanf==1)                                     /*就是检测scanf的返回值是否1，因为转换说明，也就是为scanf
                                                                指明输入的字符只能是数字才返回1，如果不是，那么不返回1*/
    {
        temper(temp);
        printf("Keep entering the Wallet /temperatures\n");
        printf("(if input_temperatures is not a number ,system quit.)\n");
        ret_scanf=scanf("%lf",&temp);
    }
    printf("System ends.\n");

    return 0;
}

void temper(double x)                       //计算摄氏温度和开尔文温度
{
    const double S_1=5.0/9.0;              //设置静态常量
    const double S_2=32.0;
    const double K_S=273.16;
    double s_temp,k_temp;

    s_temp=S_1*(x-S_2);
    k_temp=s_temp+K_S;
    printf("\nWallet temperatures %.2f F=S's temperatures %.2f ℃\n",x,s_temp);    //打印输出
    printf("=%.2f K.\n",k_temp);

}
