/*-��10��*/
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
    while(temp=strchr(st,' '))//ȱ�㣺ÿ�ζ��ô�ͷ�ҿո�
    {
        do
        {
            *temp=*(temp+1);
            temp++;
        }
        while(*temp!='\0');

    }
}

void drop_space1(char *st)      //������Լ��ú������ŵ������һ�εò��Ҷ�������һ�εû����ϲ���
{
    char *temp;
    while(*st)          //�������ַ�֮ǰ������Ч����
    {
        if(*st==' ')
        {
            temp=st;
            do
            {
                *temp=*(temp+1);
                temp++;
            }
            while(*temp);            //��û�ж������ַ��ͼ�������
        }
        else
            st++;
    }
}
