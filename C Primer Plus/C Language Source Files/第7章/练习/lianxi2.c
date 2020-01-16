#include<stdio.h>
int main(void)
{
    unsigned char count=0;
    char ch;

    printf("Enter the words for this program:\n");
    while((ch=getchar())!='#')
    {
        putchar(ch);
        printf("%4d ",(int)ch);
        count++;
        if(count%8==0)
            putchar('\n');
    }
    printf("\n");
    printf("Done\n");

    return 0;
}
