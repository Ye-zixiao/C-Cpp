#include<stdio.h>
int call_function(void);

int main(void)
{
    int count,i;

    printf("Enter the count you want to call this function.\n");
    scanf("%d",&count);
    for(i=count;i>0;i--)
    {
        printf("this program has called this function %d times\n",call_function());
    }

    return 0;
}

int call_function(void)
{
    static int call_ct=0;
    call_ct++;
    //printf("%d\n",call_ct);
    return call_ct;
}
