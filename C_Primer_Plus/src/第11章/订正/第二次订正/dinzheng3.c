/*-第10题*/
#include<stdio.h>
#include<string.h>
#define SIZE 81
char *s_gets(char *st,int n);
void drop_space(char *st);

int main(void)
{
    char input[SIZE];
    s_gets(input,SIZE);
    putchar('\n');
    puts("the string you input is:");
    puts(input);
    drop_space(input);
    puts(input);

    return 0;
}

char *s_gets(char *st,int n)
{
    char *ret_val;
    ret_val=fgets(st,n,stdin);
    if(ret_val)
    {
        while(*st!='\n'&&*st!='\0')
            st++;
        if(*st=='\n')
            *st='\0';
        else
            while(getchar()!='\n')
                continue;
    /* char *find;
        find=strchr(st,'\n');
        if(find)
            *find='\0';
        else
            while(getchar()!='\n')
                continue;
        */
    }
    return ret_val;
}

void drop_space(char *st)
{
    char *temp;
    while(temp=strchr(st,' '))//缺点：每次都得从头找空格
    {
        do
        {
            *temp=*(temp+1);
            temp++;
        }
        while(*temp!='\0');

    }
}

void drop_space1(char *st)      //相比于自己得函数得优点就是下一次得查找都是在上一次得基础上查找
{
    char *temp;
    while(*st)          //读到空字符之前都能有效进行
    {
        if(*st==' ')
        {
            temp=st;
            do
            {
                *temp=*(temp+1);
                temp++;
            }
            while(*temp);            //还没有读到空字符就继续交换
        }
        else
            st++;
    }
}
