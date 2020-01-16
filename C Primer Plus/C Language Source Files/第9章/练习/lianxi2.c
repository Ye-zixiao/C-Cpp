#include<stdio.h>
void chline(char,int,int);

int main(void)
{
    char ch='A';
    chline(ch,5,6);
    putchar('\n');
    return 0;
}

void chline(char ch,int i,int j)
{
    int m,n;

    for(m=1;m<=j;m++)
    {
        for(n=1;n<=i;n++)
            printf("%c",ch);
        putchar('\n');
    }
    return;
}
