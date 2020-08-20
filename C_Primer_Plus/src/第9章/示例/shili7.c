#include<stdio.h>
void binary(int n);

int main(void)
{
    int num;

    printf("Enter next number for this program.(q to quit)\n");
    while(scanf("%d",&num)==1)
    {
        binary(num);
        putchar('\n');
        printf("Enter next number for this program.(q to quit)\n");
    }
    printf("Done\n");

    return 0;
}

void binary(int n)          //使用递归函数进行计算
{
    int num;
    int ct;

    num=n%2;
    ct=n/2;
    if(ct>0)
        binary(ct);
    printf("%d",num);
}
