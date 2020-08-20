/*-----使用转换说明------*/
#include<stdio.h>
#define PI 3.141592
int main(void)
{
    int num=7;
    float pies=12.75;
    int costs=7800;

    printf("The %d contestants ate %.2f berry pies.\n",num,
           pies);
    printf("The value of pi is %f.\n",PI);
    printf("Farewell!thou art too dear for possessing,\n");
    printf("%c%d",'$',2*costs);

    return 0;

}
