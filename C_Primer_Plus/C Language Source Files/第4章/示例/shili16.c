/*-------演示抑制赋值*修饰符在printf()中的使用方法------*/
#include<stdio.h>
#define uint unsigned int
int main(void)
{
    uint width,precision;
    int number=256;
    double weight=242.5;

    printf("Enter a field width:\n");
    scanf("%d",&width);
    printf("The number is :%*d\n",width,number);                //width对应字段宽度，这样就可以自定义
    printf("Now enter a width and a precision:\n");
    scanf("%d %d",&width,&precision);
    printf("Weight=%*.*f\n",width,precision,weight);            //width对应字段宽度，precision对应精度
    printf("Done!\n");

    return 0;
}
