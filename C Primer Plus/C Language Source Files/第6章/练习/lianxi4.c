#include<stdio.h>
int main(void)
{
    const int HANG=6;
    int i,j;
    char ch;

    for(i=1,ch='A';i<=HANG;i++)
    {
        for(j=1;j<=i;j++,ch++)//ch���������ã�һֱ����
            printf("%c",ch);
        printf("\n");
    }

    return 0;
}
