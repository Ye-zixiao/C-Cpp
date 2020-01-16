/*-----身高转化------*/
#include<stdio.h>
int main(void)
{
    float yc;
    printf("Please enter your tall in Yingcun:");
    scanf("%f",&yc);
    printf("Your tall is %fyc in Yingcun.\n",yc);
    printf("Your tall is %fcm in Limi.\n",yc/2.54f);

    return 0;
}
