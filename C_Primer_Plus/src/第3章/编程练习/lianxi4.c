/*------��ȡС���㣬Ȼ�����------*/
#include<stdio.h>
int main(void)
{
    float num;
    printf("Enter a floating-point value: ");
    scanf("%f",&num);
    printf("fixef-point notation:%f\n",num);
    printf("exponential notation:%e\n",num);
    printf("p notation:%a\n",num);

    return 0;
}
