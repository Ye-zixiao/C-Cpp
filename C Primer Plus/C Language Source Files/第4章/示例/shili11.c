/*-------��ƥ��ĸ�����ת��------*/
#include <stdio.h>
int main(void)
{
    float n1=3.0;
    double n2=3.0;
    long n3=2000000000;
    long n4=1234567890;

    printf("%.1e %.1e %.1e %.1e \n",n1,n2,n3,n4);//������������ת��Ϊ������ʱ�����˴���
    printf("%ld %ld \n",n3,n4);                   //��ȷ
    printf("%ld %ld %ld %ld \n",n1,n2,n3,n4);    //����Ͳ���ȷ

    return 0;
}
