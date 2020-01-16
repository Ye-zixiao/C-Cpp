#include<stdio.h>
int main(void)
{
    unsigned long num;
    unsigned long div;
    _Bool isPrime;

    printf("Enter a number for this program.\n");
    printf("Enter q to quit the program.\n");
    while(scanf("%lu",&num)==1)
    {
        for(div=2,isPrime=1;(div*div)<=num;div++)
        {
            if(num%div==0)
            {
                if((div*div)!=num)
                    printf("%lu is divided by %lu and %lu.\n",
                           num,div,num/div);
                else
                    printf("%lu is divided by %lu.\n",num,
                           div);
                isPrime=0;
            }
        }
        if(isPrime==1)
            printf("%lu is prime.\n",num);
        printf("Keep entering.\n\n");
    }

    return 0;
}
