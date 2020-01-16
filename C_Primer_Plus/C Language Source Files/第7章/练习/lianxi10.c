#include<stdio.h>
#define BREAK_1 17850.0
#define BREAK_2 23900.0
#define BREAK_3 29750.0
#define BREAK_4 14875.0
#define RATE_1 0.15
#define RATE_2 0.28

int main(void)
{
    char ch;
    double wage,tax,breakwage;

    printf("You are ____?\n");
    printf("a) single                     b) householder\n");
    printf("c) married but shared         d) married but divorced\n");
    while((ch=getchar())!="q")
    {
        switch(ch)
        {
            case 'a':
                breakwage=BREAK_1;
                break;
            case 'b':
                breakwage=BREAK_2;
                break;
            case 'c':
                breakwage=BREAK_3;
                break;
            case 'd':
                breakwage=BREAK_4;
                break;
            case '\n':
                continue;
            default:
                printf("Enter the right form!\n");
        }

        printf("What is your wage?\n");
        scanf("%lf",&wage);
        if(wage<=breakwage)
            tax=wage*RATE_1;
        else
            tax=(wage-breakwage)*RATE_2+breakwage*RATE_1;
        printf("tax is %0.2f.\n",tax);

        printf("Enter the next choice");
        printf("(enter q to quit this pogram)\n");
    }
    printf("Done\n");

    return 0;
}
