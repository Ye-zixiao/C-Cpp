#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"lianxi7.h"

int main(void)
{
    int sets;
    int sides,dice;

    srand((unsigned int)time(0));
    printf("Enter the number of sets; enter q to stop: ");
    while(scanf("%d",&sets)==1)
    {
        int *ptd;
        int i;
        ptd=(int *)malloc(sets*sizeof(int));//请求动态内存

        printf("How many sides and dice? ");//给数组赋值
        scanf("%d %d",&sides,&dice);
        for(i=0;i<sets;i++)
            ptd[i]=roll_n_dice_(sides,dice);

        printf("Here are %d sets of %d %d-sided throws.\n",sets,
               dice,sides);
        for(i=0;i<sets;i++)
        {
            printf("%3d",ptd[i]);
            if((i%(15-1)==0)&&i!=0)
                putchar('\n');
        }
        if(i%(15-1)!=0)
            putchar('\n');
        free(ptd);                          //一定记得要释放动态内存

        printf("How many sets?Enter q to stop: ");
    }
    puts("Done");

    return 0;
}

