#include<stdio.h>
int main(void)
{
    const int COUNT=6;
    const int CHARS=6;

    int count;
    char ch;

    for(count=0;count<COUNT;count++)
    {
        for(ch='A'+count;ch<('A'+CHARS);ch++)
            printf("%c",ch);
        printf("\n");
    }

    return 0;
}
