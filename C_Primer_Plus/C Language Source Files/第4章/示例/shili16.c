/*-------��ʾ���Ƹ�ֵ*���η���printf()�е�ʹ�÷���------*/
#include<stdio.h>
#define uint unsigned int
int main(void)
{
    uint width,precision;
    int number=256;
    double weight=242.5;

    printf("Enter a field width:\n");
    scanf("%d",&width);
    printf("The number is :%*d\n",width,number);                //width��Ӧ�ֶο�ȣ������Ϳ����Զ���
    printf("Now enter a width and a precision:\n");
    scanf("%d %d",&width,&precision);
    printf("Weight=%*.*f\n",width,precision,weight);            //width��Ӧ�ֶο�ȣ�precision��Ӧ����
    printf("Done!\n");

    return 0;
}
