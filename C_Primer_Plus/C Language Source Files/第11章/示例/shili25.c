#include<stdio.h>
#define MAX 20
char *s_gets(char *st,int n);

int main(void)
{
    char first[MAX];
    char last[MAX];
    char formal[2*MAX+10];
    double prize;

    puts("Enter your first name:");
    s_gets(first,MAX);
    puts("Enter your last name:");
    s_gets(last,MAX);
    puts("Enter your prize money");
    scanf("%lf",&prize);
    sprintf(formal,"%s, %-19s: $%6.2f\n",last,first,prize);
    puts(formal);

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
