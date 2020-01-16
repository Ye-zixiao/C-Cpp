#include<stdio.h>
#define HOURLY_WAGE 10.0
#define FUCK_TIME_RATE 1.5

#define RATE_1 0.15
#define RATE_2 0.2
#define RATE_3 0.25

#define BREAK_1 300.0
#define BREAK_2 450.0

#define BASE_1 (BREAK_1*RATE_1)
#define BASE_2 (BASE_1+(BREAK_2-BREAK_1)*RATE_2)
#define TIME_BREAK 40

int main(void)
{
    int work_time,fuck_time=0;
    float wage,net_income,tax;

    printf("Please enter the time you work for company.\n");
    while(scanf("%d",&work_time)==1)
    {
        if(work_time>TIME_BREAK)
        {
            fuck_time=work_time-TIME_BREAK;
            fuck_time*=FUCK_TIME_RATE;
            work_time=fuck_time+TIME_BREAK;
        }
        wage=HOURLY_WAGE*work_time;
        if(wage<=BREAK_1)
            tax=RATE_1*wage;
        else if(wage>BREAK_1&&wage<=BREAK_2)
            tax=BASE_1+RATE_2*(wage-BREAK_1);
        else
            tax=BASE_2+RATE_3*(wage-BREAK_2);
        net_income=wage-tax;

        printf("wage=%0.2f,tax=%0.2f,net_income=%0.2f.\n",wage,tax,net_income);
        printf("Keep entering the work_time for this progrm(enter the q to quit this program)\n");
    }
    printf("Done\n");


    return 0;


}
