/*------6-5-------*/
#include<stdio.h>
int main(void)
{
    char ch,ch1;
    int i,j;
    int hang;

    printf("Enter an aphabet:\n");
    scanf("%c",&ch);
    hang=ch-'A'+1;

    for(i=1;i<=hang;i++)
    {
        ch1='A'-1;
        for(j=1;j<=hang-i;j++)          //�������ظ�ʹ�ñ���������̫����Ƴ����ʱ�����
            printf(" ");
        for(j=1;j<=i;j++)               //��ĸ�����򣩵��������к���ͬ
            printf("%c",++ch1);
        for(j=1;j<i;j++)                //��ĸ�����򣩵��к�Ϊ�к�-1
            printf("%c",--ch1);
        printf("\n");

    }
    printf("\n");

    return 0;
}
