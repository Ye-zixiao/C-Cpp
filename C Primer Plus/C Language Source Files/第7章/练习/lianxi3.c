#include<stdio.h>
int main(void)
{
    int o_count=0;
    int j_count=0;
    int o_sum=0;
    int j_sum=0;
    int num;
    float o_average,j_average;

    printf("Please enter a string of numbers for this program.\n");
    while(scanf("%d",&num)==1)
    {
        if(num==0)
            break;
        if(num%2==0)
        {
            o_sum+=num;
            o_count++;
        }
        else
        {
            j_sum+=num;
            j_count++;
        }
    }
    printf("o_count=%d,o_average=%.2f.\n",o_count,(float)o_sum/o_count);
    printf("j_count=%d,j_average=%.2f.\n",j_count,(float)j_sum/j_count);

    return 0;
}
