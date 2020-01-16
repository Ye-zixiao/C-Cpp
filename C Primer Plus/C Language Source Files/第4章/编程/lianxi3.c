#include<stdio.h>
int main(void)
{
    float x,y;
    printf("Enter a string of number:");
    scanf("%g",&x);
    printf("The exponational form of your input-number is:%.1f.\n",x);
    printf("The normal form of your input-number is:%.1e\n",x);

    printf("Then enter another number string:");
    scanf("%g",&y);
    printf("The exponational form of your input-number is:%+.3f.\n",y);
    printf("The normal form of your input-number is:%.3E\n",y);

    return 0;
}
