#include<stdio.h>
int main(void)
{
    int number;
    printf("Please enter a number for this program:\n");
    scanf("%d",&number);
    if(number>6)
        if(number<12)
        printf("You are closed.\n");
    else
        printf("Sorry,you lose a turn.\n");

    return 0;
}
