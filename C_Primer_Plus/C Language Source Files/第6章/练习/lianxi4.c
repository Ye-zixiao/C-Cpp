#include<stdio.h>
int main(void)
{
    const int HANG=6;
    int i,j;
    char ch;

    for(i=1,ch='A';i<=HANG;i++)
    {
        for(j=1;j<=i;j++,ch++)//ch让它不重置，一直增长
            printf("%c",ch);
        printf("\n");
    }

    return 0;
}
