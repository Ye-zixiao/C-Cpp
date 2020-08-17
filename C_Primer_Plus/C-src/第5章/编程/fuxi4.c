#include<stdio.h>
#define TEN 10
#define SEVEN 7
int main(void)
{
    int n=0;
    char ch='a';

    while(n++<TEN)
    {
        printf("%5d",n);
    }
    printf("\n");

    while(ch<='j')
    {
        printf("%5c",ch);
        ch++;
    }
    printf("\n");

    return 0;
}

/*{
    int count=0;
    int chart=97;

    printf("  num character\n");
    while(count++<SEVEN)
    {
        printf("%5d",count);
        printf("%5c\n",chart);
        chart++;
    }

    return 0;
}*/
