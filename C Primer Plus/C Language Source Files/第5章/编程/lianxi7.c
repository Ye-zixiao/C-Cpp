/*-----��ƴ��κ���������----*/
#include<stdio.h>
float cubed(float n);
int main(void)
{
    float num_input,result;
    int rv;

    printf("Please enter the number you want:\n");
    rv=scanf("%f",&num_input);
    while(rv==1)                        //�ж���������Ƿ����0��������0����whileѭ����������ֵ
    {
        result=cubed(num_input);
        printf("The number you input:%0.2f ,and \
it's cubed is %0.3f.\n",num_input,result);
        printf("Keep entering(enter the number<=0 to quit this system).\n");
        rv=0;                           //������λrv��Ϊ�˱����������ֹ��һ��rv=1��ڶ��β�����1����û�и�дrv��ֵ
        rv=scanf("%f",&num_input);
    }
    printf("System ends.\n");

    return 0;
}

float cubed(float n)                    /*ʹ�÷���ֵ�Ĵ��κ���������������������
                                            ������÷���ֵ������������԰Ѵ�ӡƽ
                                            ��ֵ��һ���ŵ����õĺ����м�*/
{
    float cubed;
    cubed=n*n*n;

    return cubed;
}
