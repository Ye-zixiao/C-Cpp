#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 10
void storeword(char *str);

int main(void)
{
    char input[SIZE];
    storeword(input);
    puts(input);

    return 0;
}

void storeword(char *str)
{
    char ch;
    while(isspace(ch=getchar()))
        continue;
    do
    {
        *str=ch;                         //�Ƚ���һ��ѭ�����ַ���ȡ�����鵱��
        str++;
    }
    while(!isspace(ch=getchar()));       //������ǿհ��ַ��Ҿͼ��������뻺�����ж�ȡ�ַ���ȱ�㣺getchar��Ե�һ�����з���������ֻ��һ�����ʵ������
    *str='\0';
    if(ch!='\n')
        while(getchar()!='\n')
            continue;
}
