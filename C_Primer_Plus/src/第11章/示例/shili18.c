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
    if(ret_val)                                 //��鷵�ص�ָ��char��ָ���Ƿ�Ϊnull
    {
        while(st[i]!='\n'&&st[i]!='\0')       //��һ��������黻�з�����Ϊ�˽���ת��Ϊ���ַ�
            i++;                                //�ڶ���������Ϊ�˼�������ַ�����SIZE�������Ϊ���ǽ����뻺���еĶ����ַ�������
        if(st[i]=='\n')
            st[i]='\0';
        else
            while(getchar()!='\n')
                continue;
    }

    return ret_val;
}
