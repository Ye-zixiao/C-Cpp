#include<stdio.h>
int main(void)
{
    int i = -1,j;
    char input[256];

    printf("Please input the string:");

    do
    {
        i++;
        scanf("%c", &input[i]);
    }
    while (input[i] != '\n');

    for (;i>=0;i--)
    {
        printf("%c", input[i]);
    }
    printf("\n");

    return 0;
}
