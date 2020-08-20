#include<stdio.h>
#include<string.h>
#define ANSWER "Grant"
#define SIZE 40
char *s_gets(char *st,int n);

int main(void)
{
    char try[SIZE];

    puts("Who is buried in Grant's tomb?");
    s_gets(try,SIZE);
    while(strcmp(try,ANSWER))
    {
        puts("No,thats wrong.Try again.");
        s_gets(try,SIZE);
    }
    puts("That's right!");

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
