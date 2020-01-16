/*-------不匹配的浮点型转换------*/
#include <stdio.h>
int main(void)
{
    float n1=3.0;
    double n2=3.0;
    long n3=2000000000;
    long n4=1234567890;

    printf("%.1e %.1e %.1e %.1e \n",n1,n2,n3,n4);//后面两个整型转化为浮点数时出现了错误
    printf("%ld %ld \n",n3,n4);                   //正确
    printf("%ld %ld %ld %ld \n",n1,n2,n3,n4);    //这里就不正确

    return 0;
}
