/*------计算自己的年龄中度过了多少秒------*/
#include<stdio.h>
int main(void)
{
    float secs,yrages;
    secs=3.156e7;
    printf("Enter you ages:");
    scanf("%f",&yrages);
    printf("You have passed %e seconds in your life.\n",yrages*secs);

    return 0;
}
