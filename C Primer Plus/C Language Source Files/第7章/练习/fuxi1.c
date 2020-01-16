#include<stdio.h>
//对原来的函数进行修改
int main(void)
{
    int weight,height;

    printf("Enter the height and weight for this program:\n");
    while(scanf("%d %d",&height,&weight)==2)
    {
        if(weight<100&&height>64)
        {
            if(height>=72)
                printf("You are very tall for this weight.\n");
            else if(height<72&&height>64)
                printf("You are tall for this height.\n");
            else
                printf("Your weight is ideal.\n");
        }
        else
            printf("You are quite short for this height.\n");
    }
    printf("Done!\n");


    return 0;
}

//这是一个错误的答案
