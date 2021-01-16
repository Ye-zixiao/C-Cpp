#include<stdio.h>
int main(void)
{
    int count=0;
    char ch;

    while((ch=getchar())!=EOF)
        count++;
    printf("The number of the chars is %d.\n",count);

    return 0;
}
