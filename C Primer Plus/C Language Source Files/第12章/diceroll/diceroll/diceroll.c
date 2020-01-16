#include<stdio.h>
#include<stdlib.h>
#include"diceroll.h"

int roll_count=0;

static int rollem(int sides)
{
    int roll;
    roll=rand()%sides+1;
    roll_count++;

    return roll;
}

int roll_n_dice(int dice,int sides)
{
    int d;
    int total=0;

    if(sides<2)
    {
        printf("Need at least 2 sides.\n");
        return -2;
    }
    if(dice<1)
    {
        puts("Need at least 1 die.");
        return -1;
    }

    for(d=0;d<dice;d++)
    {
        printf("total=%d\n",total);//用于检查错误
        total+=rollem(sides);
    }
    printf("total=%d\n",total);//用于当时检查错误之用

    return total;
}
