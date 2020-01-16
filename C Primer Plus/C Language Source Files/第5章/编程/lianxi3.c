#include<stdio.h>
const int D_W=7;
int main(void)
{
    int input_days,weeks,days;
    printf("Input the number of days that you want.(input<=0,system,ends.)\n");
    scanf("%d",&input_days);
    while(input_days>0)
    {
        weeks=input_days/D_W;
        days=input_days%D_W;
        printf("%d days are %d weeks,%d days.\n",
               input_days,weeks,days);
        printf("Keep entering.\n");
        scanf("%d",&input_days);
    }
    printf("System ends.\n");

    return 0;
}
