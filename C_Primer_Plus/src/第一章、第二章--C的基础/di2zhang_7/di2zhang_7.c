/*-------��ӡ���smile--------*/
//��2�µ�7��
#include<stdio.h>
void sm(void);
void huanhang(void);
int main(void)
{
    int i,j;
    for(i=3;i>0;i--)            //��ӡ������smile
    {
        sm();
    }
    huanhang();
    //printf("\n");

    for(j=2;j>0;j--)            //��ӡ��2��smile
    {
        sm();
    }
    huanhang();
    //printf("\n");

    sm();                         //��ӡ��һ��smile
    huanhang();
    //printf("\n");

    return 0;
}

void sm(void)
{
    printf("Smile!");
}

void huanhang(void)
{
    printf("\n");
}
