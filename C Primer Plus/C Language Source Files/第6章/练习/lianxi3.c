#include<stdio.h>
int main(void)
{
    const int HANG=6;
    int i,j;
    char ch;

    for(i=1;i<=HANG;i++)
    {
        for(j=1,ch='F';j<=i;j++,ch--)
            printf("%c",ch);
        printf("\n");
    }
    return 0;
}
