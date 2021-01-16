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
        for(j=1;j<=hang-i;j++)          //尽量多重复使用变量，变量太多设计程序的时候很乱
            printf(" ");
        for(j=1;j<=i;j++)               //字母（增序）的列数与行号相同
            printf("%c",++ch1);
        for(j=1;j<i;j++)                //字母（降序）的列号为行号-1
            printf("%c",--ch1);
        printf("\n");

    }
    printf("\n");

    return 0;
}
