/*-------����ģֵ���ҵ����Զ���------*/
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
    while(fir_num>0)                                 //�����ж�����ĵ�һ��ֵ�Ƿ����0��������0����������㲢��ӡ
    {
        mod(fir_num,sec_num);
        printf("Enter next number for first operand (<= 0 to quit):");
        scanf("%d",&fir_num);
    }
    printf("Done.\n");

    return 0;
}

void mod(int first_oper,int sec_oper)               //ʹ�ò��������ֵĴ��κ���ȥ����ģֵ����ӡ
{
    int result;
    result=first_oper%sec_oper;
    printf("%d %% %d is %d\n",first_oper,sec_oper,
           result);
}
