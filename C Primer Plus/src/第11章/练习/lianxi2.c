#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 15
void storechar(char *str,int n);

int main(void)
{
    char input[SIZE];

    storechar(input,SIZE);
    puts(input);

    return 0;
}

void storechar(char *str,int n)
{
    fgets(str,n,stdin);
    while(!isspace(*str))//����ȡ���հ��ַ�ʱ������
        str++;
    if(*str!='\0')
        *str='\0';
}
