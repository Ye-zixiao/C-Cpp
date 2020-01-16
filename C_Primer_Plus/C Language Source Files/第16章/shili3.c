#include<stdio.h>
#define PSQR(x) printf("The square of " #x " is %d.\n",((x)*(x)))   //这里用了字符串串联功能
#define PSQR1(x) printf("The square of %s is %d.\n",#x,((x)*(x)))
int main(void)
{
    int y=5;

    PSQR(y);
    PSQR(2+4);
    PSQR1(2+5);

    return 0;
}
