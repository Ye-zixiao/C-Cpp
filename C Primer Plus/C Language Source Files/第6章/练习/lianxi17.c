#include<stdio.h>
#define MONEY 100.0
#define RATE 0.08
#define WITHDRAW 10.0

int main(void)
{
    int years=0;
    double balance=MONEY;

    do
    {
        balance*=(RATE+1);
        balance-=WITHDRAW;
        years++;
        printf("The balance is %.2f \n",balance);
    }
    while(balance>0);
    printf("Chuckie Lucky needs %d years to quit his money.\n",years);

    return 0;
}
