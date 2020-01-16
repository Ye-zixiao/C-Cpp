#include<stdio.h>
int main(void)
{
    const int FREEZING=0;
    float temp;
    int all_days=0,cold_days=0;

    printf("Enter the list of daily low temperature.\n");
    printf("Use Celsius,and enter any aphabet to quit this program.\n");
    while(scanf("%f",&temp)==1)
    {
        all_days++;
        if(temp<FREEZING)
        {
            cold_days++;
        }
    }

    if(all_days!=0)
    {
        printf("%d days total:%.1f%% were below the freezing.\n",
               all_days,100.0*cold_days/all_days);//数据类型会被程序自动转换
    }
    if(all_days==0)
        printf("No data entered.\n");

    return 0;
}
