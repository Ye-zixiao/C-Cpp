#include<stdio.h>
void change(float *px,float *py,float *pz);

int main(void)
{
    float x=1.2;
    float y=5.6;
    float z=2.1;

    printf("Originally, x=%0.2f y=%0.2f and z=%0.2f\n",x,y,z);
    change(&x,&y,&z);
    printf("Now,x=%0.2f y=%0.2f and z=%0.2f\n",x,y,z);

    return 0;
}

void change(float *px,float *py,float *pz)
{
    float temp;
    if(*px>*py)//��һ���͵ڶ������бȽϽ���
    {
        temp=*px;
        *px=*py;
        *py=temp;
    }
    if(*py>*pz)//�ڶ����͵��������бȽϽ���
    {
        temp=*py;
        *py=*pz;
        *pz=temp;
    }
    if(*px>*py)//�µĵ�һ�����µĵڶ������бȽϽ���
    {
        temp=*px;
        *px=*py;
        *py=temp;
    }
}
