#include<stdio.h>
#include<stdlib.h>
//#include"lianxi7.h"

static rand_num(int sides)
{
    return rand()%sides+1;
}

int roll_n_dice_(int sides,int dice)
{
    int total=0;
    int i;
    for(i=0;i<dice;i++)
        total+=rand_num(sides);

    return total;
}
