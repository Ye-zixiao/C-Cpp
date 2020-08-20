#include<stdio.h>
int main(void)
{
    int guess=1;
    char response;

    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nRespond with a y if my guess is right and with");
    printf("\nan n if it is wrong.\n");
    printf("Uh...is your number %d?\n",guess);
    while((response=getchar())!='y')//如果回答了n（不是），就进入循环
    {
        if(response=='\n')              //这样就解决了不断输入回车符的漏洞
            continue;
        if(response=='n')                       //整队其他字符
            printf("Well, then ,is it %d?\n",++guess);
        else
            printf("Sorry,I understand only y or n\n");

        while(getchar()!='\n')
            continue;
    }
    printf("I knew I could do it!\n");

    return 0;
}
