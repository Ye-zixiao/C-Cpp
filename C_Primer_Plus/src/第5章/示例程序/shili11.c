#include<stdio.h>
int main(void)
{
    int a=1,b=1;
    int a_post,pre_b;

    a_post=a++;           //�Ƚ���++ǰ�ı��ʽ��Ȼ������
    pre_b=++b;            //���������ٽ��б��ʽ
    printf("%1d %5d %5d %5d \n",a,a_post,b,pre_b);

    return 0;
}
