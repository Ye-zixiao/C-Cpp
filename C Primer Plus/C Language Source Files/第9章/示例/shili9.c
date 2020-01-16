#include<stdio.h>
void chat(int m,int n);

int main(void)
{
    int i,j;
    int hang;

    printf("Enter the rows(q to quit):\n");
    while(scanf("%d",&hang)==1)
    {
        if(hang>=26)
        {
            printf("That's too big\n");
            goto ju1;
        }

        for(i=1;i<=hang;i++)
        {
            for(j=1;j<=hang-i;j++)
                putchar(' ');
            chat(1,i);
            putchar('\n');
        }
        putchar('\n');
        ju1:printf("Enter the rows(q to quit):\n");
    }

    return 0;
}

void chat(int m,int n)              //m计数值，n打印几个不同的字母
{
    char ch='A'-1;

    putchar(ch+m);
    if(m<n)
        chat(m+1,n);
    if(m<n)                          //当m计数到n（行序号）时，不再重复打印这个字符
        putchar(ch+m);
}
