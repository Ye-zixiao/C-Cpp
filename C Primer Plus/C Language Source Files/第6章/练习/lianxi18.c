#include<stdio.h>
#define DUNBAR 150

int main(void)
{
    int weeks=0;
    int friends=5;

    do
    {
        weeks++;
        friends-=weeks;
        friends*=2;
        printf("The balance of Rabnud is %d.\n",friends);
    }
    while(friends<DUNBAR);
    printf("Doc.Rabnud needs %d weeks to exceed the Dunbar number.\n",weeks);

    return 0;
}
