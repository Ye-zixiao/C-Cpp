/*-第6题*/
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
    //return *st;                 //如果找到了ch，那么就会返回一个非零值，若没有则返回空字符
    /*if(*st!='\0')
        return true;
    else
        return false;*/
    return (*st!='\0')?true:false;//这样的话比return *st更清晰一点意思
}
