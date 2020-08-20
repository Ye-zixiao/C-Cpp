/*--------第三章的第一个示例程序--------*/
#include <stdio.h>
int main()
{
    float weight,value;

    printf("Are you worth your weight in platinum?\n");
    printf("Let's check it out.\n");
    printf("Please enter your weight in pounds:\n");

    scanf("%f",&weight);                                                    //%f 代表输入值什么样的字符， &某 表示输入

    value=1700.0*weight*14.5833;
    printf("Your weight in platinum is worth $%.2f\n",value);               /*总的来说是一个转化程序，
                                                                            其中   %.2f   应该表示用一个小数点保留后面2位的数代替*/
    printf("You are easily worth that!If platinum prices drop,\n");
    printf("eat more to maintain your value.\n");

    return 0;

}
