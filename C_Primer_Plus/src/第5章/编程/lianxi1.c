#include<stdio.h>
#define F_S 60
int main(void)
{
    int min,hour,input_min;
    printf("Enter the time in the form of minutes.If the input<=0,\
we will finish this program.\n");
    scanf("%d",&input_min);
    while(input_min>0)
    {
        hour=input_min/F_S;
        min=input_min%F_S;
        printf("The time you inputs is %d:%d.\n",hour,min);
        printf("Please input the time again:\n");
        scanf("%d",&input_min);
    }
    printf("System over.\n");

    return 0;
}
