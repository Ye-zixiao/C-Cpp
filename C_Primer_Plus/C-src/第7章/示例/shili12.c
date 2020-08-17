#include<stdio.h>
#include<ctype.h>

int main(void)
{
    char ch;

    printf("Give me a letter of aphabet ,and I will give ");
    printf("an animal name\nbeginning with that letter.\n");
    printf("Please type in a letter;type # to end my act.\n");
    while((ch=getchar())!='#')
    {
        if('\n'==ch)
            continue;
        if(islower(ch))
            switch(ch)
        {
            case 'a':
                printf("argali\n");
                break;
            case 'b':
                printf("babirusa\n");
                break;
            case 'c':
                printf("coati\n");
                break;
            default:
                printf("That's a stumper!\n");
        }
        else
            printf("I recognize only lowercase letter.\n");
        while(getchar()!='\n')                  //这一行完全是为了消除首字母后面的字母，详情见P205，直到按下回车键时才推出
            continue;
/*        while(getchar()!='\n')
            continue;*/
            //好像没有这个while语句好像也完全可以
        printf("Please type another letter or a # .\n");
    }
    printf("Bye.\n");

    return 0;
}
