#include<stdio.h>
int main(void)
{
    int i,j,list[10];

    for(i=0;i<=9;i++)               //ע������list[10]�Ǵ�0��9�����±������
    {
        list[i]=2*i+3;
        for(j=0;j<=i;j++)
            printf(" %d",list[j]);
        printf("\n");
    }

    return 0;
}
