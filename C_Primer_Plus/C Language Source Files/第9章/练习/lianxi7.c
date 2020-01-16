#include<stdio.h>
#include<ctype.h>
#define CHANGE 64
int recognition(char ch);

int main(void)
{
    char ch;
    int count=0;

    printf("Please input the words you want:\n");
    while((ch=getchar())!=EOF)
    {
        if(ch=='\n')
            continue;
        printf("%4d",recognition(ch));
        if(count++==8)
        {
            count=0;
            putchar('\n');
        }
    }
    printf("Done\n");

    return 0;
}

int recognition(char ch)
{
    int ans;
    if(isalpha(ch))
    {
        ch=toupper(ch);
        ans=(int)ch-CHANGE;
    }
    else
        ans=-1;

    return ans;
}
