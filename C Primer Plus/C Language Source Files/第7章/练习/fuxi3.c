#include<stdio.h>
int main(void)
{
    char ch;

    ch=getchar();
    while(ch!='#'&&ch!='b')
    {
        switch(ch)
        {
            case '\n':
                break;
            case 'c':
                printf("Step1\n");
                break;
            case 'h':
                printf("Step1\n");
                printf("Step3\n");
                break;
            default:
                printf("Step1\n");
                printf("Step2\n");
                printf("Step3\n");
                break;
        }
        ch=getchar();
    }
    if(ch='b')
        printf("Step1\n");
    printf("Done\n");

    return 0;
}
