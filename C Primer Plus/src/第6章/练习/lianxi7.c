#include<stdio.h>
#include<string.h>
int main(void)
{
    int i,word_length;
    char ch[20];

    printf("Enter a word.\n");
    scanf("%s",ch);
    word_length=strlen(ch);
    for(i=word_length-1;i>=0;i--)
        printf("%c",ch[i]);
    printf("\n");

    return 0;
}
