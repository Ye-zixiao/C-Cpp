/*-��6��*/
#include<stdio.h>
#include<stdbool.h>
bool is_within(char *st,char ch);

int main(void)
{
    if(is_within("hats",'s'))
        puts("in");
    else
        puts("no");

    return 0;

}

bool is_within(char *st,char ch)
{
    while(*st!='\0'&&*st!=ch)
        st++;
    //return *st;                 //����ҵ���ch����ô�ͻ᷵��һ������ֵ����û���򷵻ؿ��ַ�
    /*if(*st!='\0')
        return true;
    else
        return false;*/
    return (*st!='\0')?true:false;//�����Ļ���return *st������һ����˼
}
