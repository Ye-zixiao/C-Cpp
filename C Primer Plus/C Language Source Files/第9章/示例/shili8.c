#include<stdio.h>
#define ulong unsigned long
void to_binary(ulong n);

int main(void)
{
    ulong num;
    printf("Enter an integer (q to quit):\n");
    while(scanf("%lu",&num)==1)
    {
        printf("Binary equivalent: ");
        to_binary(num);
        putchar('\n');
        printf("Enter an integer (q to quit):\n");
    }
    printf("Done\n");

    return 0;
}

void to_binary(ulong n)                 //基本上和自己的思路相似，当然一开始的原理就是他的
{
    int r;

    r=n%2;
    if(n>=2)
        to_binary(n/2);
   // putchar(r==0?'0':'1');
    printf("%d",r);                 //上下两个语句效果完全一致

    return;
}
