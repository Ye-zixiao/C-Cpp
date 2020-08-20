#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define uint unsigned int

extern uint rand0(void);
extern void change_rand0(uint seed);

int main(void)
{
    int count;
    uint seed;

    /*printf("Please enter your choice for seed.\n");
    while(scanf("%u",&seed)==1)
    {
        change_rand0((uint)time(0));
        for(count=1;count<5;count++)
            printf("%u\n",rand0());
        puts("Please enter next seed (q to quit):");
    }*/
    int i=0;
    while(i++<5)
    {
        change_rand0((uint)time(0));
        for(count=1;count<5;count++)
            printf("%u\n",rand0());
        putchar('\n');
    }
    puts("Done");

    return 0;
}
