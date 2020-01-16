#include<stdio.h>
#include<stdlib.h>

int rand_num(int range);
int roll_n_dice(int sides,int dice);

int main(void)
{
    int sets;
    int sides,dice;

    printf("Enter the number of sets; enter q to stop: ");
    while(scanf("%d",&sets)==1)
    {
        if(sets<=0)
        {
            printf("warning:sets must bigger than 0.\n");
            printf("enter again: ");
            continue;
        }
        printf("How many sides and how many dice? ");
        scanf("%d %d",&sides,&dice);
        int i;
        for(i=0;i<sets;i++)
        {
            printf("%3d",roll_n_dice(sides,dice));//获得数字就立即输出
            if(i%15==14)
                putchar('\n');
        }
        if(sets%15!=0)
            putchar('\n');
        printf("How many sets?Enter q to stop: ");
    }
    printf("Done.\n");

    return 0;

}

int rand_num(int range)
{
    return rand()%range+1;
}

int roll_n_dice(int sides,int dice)
{
    int i;
    int total=0;

    for(i=0;i<dice;i++)
        total+=rand_num(sides);

    return total;
}
