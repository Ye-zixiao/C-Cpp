/*--------�����µĵ�һ��ʾ������--------*/
#include <stdio.h>
int main()
{
    float weight,value;

    printf("Are you worth your weight in platinum?\n");
    printf("Let's check it out.\n");
    printf("Please enter your weight in pounds:\n");

    scanf("%f",&weight);                                                    //%f ��������ֵʲô�����ַ��� &ĳ ��ʾ����

    value=1700.0*weight*14.5833;
    printf("Your weight in platinum is worth $%.2f\n",value);               /*�ܵ���˵��һ��ת������
                                                                            ����   %.2f   Ӧ�ñ�ʾ��һ��С���㱣������2λ��������*/
    printf("You are easily worth that!If platinum prices drop,\n");
    printf("eat more to maintain your value.\n");

    return 0;

}
