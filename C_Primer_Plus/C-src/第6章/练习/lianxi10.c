#include<stdio.h>
int qur_sum(int x,int y);
int main(void)
{
    int lower,upper;

    printf("Please enter the lower and upper integer limits:");
    while(scanf("%d %d",&lower,&upper)==2,upper>lower)//用逗号运算符去进行两个判断条件的给出
    {
        printf("The sums of the squares from %d to %d is %d.\n",lower,upper,sqr_sum(upper,lower));
        printf("Enter the next set of limits:");
    }
    printf("Done.\n");

    return 0;

}

int sqr_sum(int x,int y)
{
    int sum=0;

    while(x>=y)
    {
        sum+=y*y;
        y++;
    }

    return sum;
}
