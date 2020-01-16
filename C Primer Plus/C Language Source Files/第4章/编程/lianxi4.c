#include<stdio.h>
int main(void)
{
    char name[10];
    float tall;
    printf("Enter your name:\n");
    scanf("%s",name);
    printf("OK,and how tall are you in cm?\n");
    scanf("%g",&tall);

    printf("Good!%s,you are %.3f m tall.\n",name,tall/100.0f);

    return 0;
}
