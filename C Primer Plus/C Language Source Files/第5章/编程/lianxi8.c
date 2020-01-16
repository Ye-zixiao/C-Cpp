/*-------计算模值，且底数自定义------*/
#include<stdio.h>
void mod(int first_oper,int sec_oper);
int main(void)
{
    int sec_num,fir_num,result;

    printf("This program computes moduli.\n");
    printf("Enter the integer to serve as the second operand:");
    scanf("%d",&sec_num);
    printf("Now enter the first operand:");
    scanf("%d",&fir_num);
    while(fir_num>0)                                 //不断判断输入的第一个值是否大于0，若大于0，则继续计算并打印
    {
        mod(fir_num,sec_num);
        printf("Enter next number for first operand (<= 0 to quit):");
        scanf("%d",&fir_num);
    }
    printf("Done.\n");

    return 0;
}

void mod(int first_oper,int sec_oper)               //使用不返回数字的带参函数去计算模值并打印
{
    int result;
    result=first_oper%sec_oper;
    printf("%d %% %d is %d\n",first_oper,sec_oper,
           result);
}
