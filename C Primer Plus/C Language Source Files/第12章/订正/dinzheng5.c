#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 81

int main(void)
{
    int words_num;
    char **words;

    printf("How many words do you wish to enter? ");
    scanf("%d",&words_num);
    words=(char **)malloc(words_num*sizeof(char **));

    char temp[SIZE];
    int i;
    printf("Enter %d words now:\n ",words_num);
    for(i=0;i<words_num;i++)
    {
        scanf("%s",temp);
        int word_length=strlen(temp);
        words[i]=(char *)malloc(word_length+1);
        strcpy(words[i],temp);
    }

    printf("Here are your words:\n");
    for(i=0;i<words_num;i++)
        puts(words[i]);
    for(i=0;i<words_num;i++)
        free(words[i]);
    free(words);

    puts("Done.");
    return 0;
}
