#include<stdio.h>
int main(void)
{
    long num;
    long sum=0L;            //³õÊ¼»¯¸³Öµ
    int status;

    printf("Please enter an integer to be summed ");
    printf("(any aphabet to quit): ");
    status=scanf("%ld",&num);
    while(status==1)
    {
        sum+=num;
        printf("Please enter next integer (any aphabet to quit): ");
        status=scanf("%ld",&num);
    }
    printf("Those integers sum to %ld.\n",sum);

    return 0;
}
