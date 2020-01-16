#include<stdio.h>

int main(void)
{
    int units;

    printf("How many pounds to a firkin of butter?\n");
    scanf("%d",&units);
    while(units!=56)
    {
        printf("No luck,my friend.Try again.\n");
        scanf("%d",&units);
    }
    printf("You must looked it up!\n");

    return 0;
}
