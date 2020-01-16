#include<stdio.h>
int main(void)
{
    const char period='.';
    char ch;
    int num=0;

    printf("Enter a string for this program.\n");
    while((ch=getchar())!=period)
    {
        if(ch!='"'&&ch!='\'')
            num++;
    }
    printf("There is %d characters.\n",num);

    return 0;
}
