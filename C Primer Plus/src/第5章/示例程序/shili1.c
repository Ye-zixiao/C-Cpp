/*------将鞋码转化成英寸-----*/
#include<stdio.h>
#define ADJUST 7.31
int main(void)
{
    const double SCALE=1.0/3.0;
    double shoe,foot;

    shoe=43.0;
    foot=SCALE*shoe+ADJUST;
    printf("Shoe size (men's)    foot lenth\n");
    printf("%10.1f %15.2f inches\n",shoe,foot);

    return 0;
}
