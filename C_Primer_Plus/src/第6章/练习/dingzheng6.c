#include<stdio.h>
#define MONEY 100.0
#define RATE_1 0.1
#define RATE_2 0.05

int main(void)
{
    int years=0;
    double sum1=MONEY,sum2=MONEY;

    do
    {
        years++;
        sum1+=MONEY*RATE_1; //算术增长
        sum2*=(1+RATE_2);   //几何增长
    }
    while(sum1>sum2);

    printf("Deirdre needs %d yeas.\n",years);
    printf("At this time,Daphne=%.3f,Deirdre=%.3f.\n",sum1,sum2);

    return 0;
}
