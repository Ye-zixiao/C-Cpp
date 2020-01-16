/*-------使用不同的字符串------*/
#include<stdio.h>
#include<string.h>
#define PRAISE "You are an extraordinary being!"
int main(void)
{
    char name[40];

    printf("What's your name?");
    scanf("%s",name);
    printf("Hello,%s.%s\n",name,PRAISE);
    printf("Your name of %zd letters occupied %zd memory cells.\n",strlen(name),sizeof name);
    printf("The phare of praise has %zd letters ",strlen(name));
    printf("and occupied %zd memory cells.\n",sizeof PRAISE);

    return 0;
}
