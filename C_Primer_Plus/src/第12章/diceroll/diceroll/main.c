#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"diceroll.h"

int main(void)
{
    int dice;
    int roll;
    int sides;
    int status;

    srand((unsigned int)time(0));
    puts("Enter the number of sides per die, 0 to stop.");
    while(scanf("%d",&sides)==1&&sides>1)
    {
        puts("How many dice?");             //dice和die都是骰子的意思
        if((status=scanf("%d",&dice))!=1)
        {
            if(status==EOF)
                break;
            else
            {
                puts("You should have entered an integer.");
                puts("Let's begin again.");
                while(getchar()!='\n')
                    continue;
                puts("How many sides?Enter 0 to stop.");
                continue;
            }
        }
        roll=roll_n_dice(dice,sides);                               //
        printf("roll =%d\n",roll);
        printf("You have rolled a %d using %d %d-sided dice.\n",
               roll,dice,sides);
        printf("How many sides?Enter 0 to stop.\n");
    }
    printf("The rollem() function was called %d times.\n",
           roll_count);

    puts("Good fortune to you!");

    return 0;
}
