/*----------��ʾ�������---------*/
#include<stdio.h>
int main(void)
{
    float a,b;
    double c;

    b=2.0e20+1.0;
    a=b-2.0e20;
    c=1.6e29+1.6e27;
    printf("%f\n",a);//�������ڼ����ȱ���㹻��С��λ�������ȷ������
    printf("%e\n",c);//��ȷ
    return 0;

}
