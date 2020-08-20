#include<stdio.h>
int main(void)
{
    int jh_count=0,gt_count=0;
    char ch;

    while((ch=getchar())!='#')
    {
        switch(ch)
        {
            case '.':
                jh_count++;
                putchar('!');
                break;
            case '!':
                gt_count++;
                putchar(ch);
                putchar('!');
                break;
            default:
                putchar(ch);
                break;
        }
    }
    printf("\n");
    printf("jh_count=%d,gt_count=%d.\n",jh_count,gt_count);

    return 0;
}
