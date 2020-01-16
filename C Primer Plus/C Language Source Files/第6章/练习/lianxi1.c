#include<stdio.h>
#define APHA 26
int main(void)
{
    int i,j;
    char ch[26];

    for(i=0;i<APHA;i++)
        ch[i]=i+'a';
    for(j=0;j<APHA;j++)
        printf("%c",ch[j]);
    printf("\n");

    return 0;
}
