#include<stdio.h>
int main(void)
{
    const int code_num=758911;
    int input_code;

    do
    {
        printf("To enter the triskaidekaphobia therapy club,\n");
        printf("please enter the secret code number:\n");
        scanf("%d",&input_code);
    }
    while(input_code!=code_num);
    printf("Congratulation! You are cured.\n");

    return 0;
}
