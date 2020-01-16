#include<stdio.h>
#include<string.h>
#define SIZE 40
#define TARGSIZE 7
#define LIM 5
char *s_gets(char *st,int n);

int main(void)
{
    char qwords[LIM][TARGSIZE];
    char temp[SIZE];
    int i=0;

    printf("Enter %d words beginning with q:\n",LIM);
    while(i<LIM&&s_gets(temp,SIZE))
    {
        if(temp[0]!='q')
            printf("%s doesn't begin with q!\n",temp);
        else
        {
            strncpy(qwords[i],temp,TARGSIZE-1);
            qwords[i][TARGSIZE-1]='\0';
            i++;
        }
    }
    puts("Here are the words accepted:");
    for(i=0;i<LIM;i++)
        puts(qwords[i]);

    return 0;
}

char *s_gets(char *st,int n)
{
    char *ret_val;
    int i=0;

    ret_val=fgets(st,n,stdin);
    if(ret_val)                                 //检查返回的指向char的指针是否为null
    {
        while(st[i]!='\n'&&st[i]!='\0')       //第一个条件检查换行符，是为了将其转化为空字符
            i++;                                //第二个条件是为了检查输入字符多于SIZE的情况，为的是将输入缓冲中的多余字符消除掉
        if(st[i]=='\n')
            st[i]='\0';
        else
            while(getchar()!='\n')
                continue;
    }

    return ret_val;
}
