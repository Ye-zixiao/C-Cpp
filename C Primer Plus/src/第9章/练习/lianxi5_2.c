//ָ�뷨
#include<stdio.h>
void change(double *px,double *py);

int main(void)
{
    double x=1.5,y=6.3;

    printf("Originally,x=%0.2f and y=%0.2f\n",x,y);
    change(&x,&y);
    printf("Now,x=%0.2f and y=%0.2f\n",x,y);

    return 0;
}

void change(double *px,double *py)//�Ե�̫�����ˣ����������м������ʹ��
{
    double temp;
    temp=*px>*py?*px:*py;
    *px=*py=temp;
}
