#include<stdio.h>
void interchange(int *u,int *v);

int main(void)
{
    int x=5,y=10;

    printf("Originally x=%d and y=%d.\n",x,y);
    interchange(&x,&y);                             //��x��y�ĵ�ַ��������õĺ������Ӻ�����
    printf("Now, x=%d and y=%d.\n",x,y);

    return 0;
}

void interchange(int *u,int *v)                     //�β�����������ָ��
{
    int temp;

    temp=*u;                                         //��ָ��uָ��ı�����ֵ����temp
    *u=*v;                                           //��ָ��v��ָ��ı�����ֵ����ָ��u��ָ��ı���
    *v=temp;                                         //������temp��ֵ����ָ��v��ָ��ı���

    return;
}
