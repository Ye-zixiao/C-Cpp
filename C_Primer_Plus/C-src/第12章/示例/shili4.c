#include<stdio.h>
int units=0;
void critic(void);

int main(void)
{
    extern int units;

    puts("How many pounds to a firkin of butter?");
    scanf("%d",&units);
    while(units!=56)
        critic();
    puts("You must have looked it up!");

    return 0;
}

void critic(void)
{
    puts("No luck,my friend.Try again.");
    scanf("%d",&units);
    return;
}
