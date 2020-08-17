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
    if(*px>*py)//第一个和第二个进行比较交换
    {
        temp=*px;
        *px=*py;
        *py=temp;
    }
    if(*py>*pz)//第二个和第三个进行比较交换
    {
        temp=*py;
        *py=*pz;
        *pz=temp;
    }
    if(*px>*py)//新的第一个和新的第二个进行比较交换
    {
        temp=*px;
        *px=*py;
        *py=temp;
    }
}
