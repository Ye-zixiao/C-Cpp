/*--------调用子函数打印-----*/
#include<stdio.h>
void jolly();
void deny();
int main(void)
{
    jolly();
    jolly();
    jolly();
    deny();

    return 0;
}

void jolly(void)
{
    printf("For he's a jolly fellow!\n");
}

void deny(void)
{
    printf("Which nobody can deny!\n");
}
