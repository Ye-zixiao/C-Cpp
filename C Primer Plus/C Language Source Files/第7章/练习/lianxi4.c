#include<stdio.h>
int main(void)
{
    char ch;
    int jh_count=0,gt_count=0;//句号计数值和逗号计数值

    while((ch=getchar())!='#')
    {
        if(ch=='.')
        {
            putchar('!');
            jh_count++;
        }
        else if(ch=='!')
        {
            putchar(ch);
            putchar('!');
            gt_count++;
        }
        else
            putchar(ch);
    }
    printf("\n");
    printf("jh_count=%d.\n",jh_count);
    printf("gt_count=%d.\n",gt_count);

    return 0;
}
