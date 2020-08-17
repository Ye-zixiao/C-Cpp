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
        *str=ch;                         //先将上一个循环的字符读取到数组当中
        str++;
    }
    while(!isspace(ch=getchar()));       //如果不是空白字符我就继续从输入缓冲区中读取字符。缺点：getchar会吃掉一个换行符（出现在只有一个单词的情况）
    *str='\0';
    if(ch!='\n')
        while(getchar()!='\n')
            continue;
}
