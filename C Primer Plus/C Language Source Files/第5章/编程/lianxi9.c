/*-------�������¶�ת��Ϊ�����¶ȺͿ����¶�-----*/
#include<stdio.h>
void temper(double x);
int main(void)
{
    double temp;
    int ret_scanf;

    printf("This program is using for calculatering the\n");
    printf(" S's temperatures and K's temperatures.\n");
    printf("Enter the Wallet temperatures that you want:");

    ret_scanf=scanf("%lf",&temp);                           //���ϼ��������ַ��Ƿ��������ַ������������whileѭ��
    while(ret_scanf==1)                                     /*���Ǽ��scanf�ķ���ֵ�Ƿ�1����Ϊת��˵����Ҳ����Ϊscanf
                                                                ָ��������ַ�ֻ�������ֲŷ���1��������ǣ���ô������1*/
    {
        temper(temp);
        printf("Keep entering the Wallet /temperatures\n");
        printf("(if input_temperatures is not a number ,system quit.)\n");
        ret_scanf=scanf("%lf",&temp);
    }
    printf("System ends.\n");

    return 0;
}

void temper(double x)                       //���������¶ȺͿ������¶�
{
    const double S_1=5.0/9.0;              //���þ�̬����
    const double S_2=32.0;
    const double K_S=273.16;
    double s_temp,k_temp;

    s_temp=S_1*(x-S_2);
    k_temp=s_temp+K_S;
    printf("\nWallet temperatures %.2f F=S's temperatures %.2f ��\n",x,s_temp);    //��ӡ���
    printf("=%.2f K.\n",k_temp);

}
