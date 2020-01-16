#include<stdio.h>
void to_base(int num,int base);

int main(void)
{
    int num,base;

    printf("Please enter a number for this program\n");
    while(scanf("%d",&num)==1)
    {
        printf("Please enter the base number for this program\n");
        int flag;
        while((flag=scanf("%d",&base))==1&&(base<2||base>10))
        {
            printf("Please enter the right form\n");
        }
        if(flag!=1)
            break;
        printf("The equalivent form of first inputing number is:\n");
        to_base(num,base);
        putchar('\n');
        printf("Please enter a number for this program\n");
    }
    printf("Done\n");

    return 0;
}

void to_base(int num,int base)
{
    int res;

    res=num%base;
    num/=base;
    if(num>0)
        to_base(num,base);
    printf("%d",res);

    return;
}
