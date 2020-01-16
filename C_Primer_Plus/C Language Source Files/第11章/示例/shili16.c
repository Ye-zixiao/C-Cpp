#include<stdio.h>
#include<string.h>
#define SIZE 80
char *s_gets(char *st,int n);

int main(void)
{
    char flower[SIZE];
    char addon[]="s smell like old shoes.";

    puts("What is your favoriate flower?");
    if(s_gets(flower,SIZE))
    {
        strcat(flower,addon);
        puts(flower);
        puts(addon);
    }
    else
        puts("End of file encountered!");
    puts("bye!");

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
