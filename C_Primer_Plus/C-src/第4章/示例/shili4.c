/*---------常用的明示常量--------*/
#include<stdio.h>
#include<limits.h>
#include<float.h>

int main(void)
{
    printf("float的尾数的位数:%d\n",FLT_MANT_DIG);
    printf("float的最小有效数字数:%d\n",FLT_DIG);
    printf("float的最小负指数:%d\n",FLT_MIN_10_EXP);
    printf("float的最大正指数:%d\n",FLT_MAX_10_EXP);
    printf("float的最小值:%d\n",FLT_MIN);
    printf("float的最大值:%d\n",FLT_MAX);

    return 0;

}
