#include<stdio.h>
#define COVERAGE 350
int main(void)
{
    int sq_feet;
    int cans;

    printf("Enter number of square feet to paint:\n");
    while(scanf("%d",&sq_feet)==1)
    {
        cans=sq_feet/COVERAGE;
        cans+=((sq_feet%COVERAGE==0)?0:1);
        printf("You need %d %s of paint.\n",cans,cans==1?"can":"cans");
        printf("Enter next value (input any aphabet to quit this program.\n");
    }

    return 0;
}
