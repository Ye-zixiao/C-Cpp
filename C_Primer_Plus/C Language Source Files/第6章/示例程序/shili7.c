#include<stdio.h>
#define bool _Bool                  //����ʹ��ͷ�ļ�stdbool.h
int main(void)
{
    long num;
    long sum=0L;
    bool input_is_good;            //��������

    printf("Please enter an integer to be summed.\n");
    printf("(any aphabet to quit this program.)\n");
    input_is_good=scanf("%ld",&num);
    while(input_is_good)
    {
        sum+=num;
        printf("Please enter next integer (any aphabe to quit).\n");
        input_is_good=scanf("%ld",&num);
    }
    printf("Those integer sum to %ld.\n",sum);

    return 0;
}
