#include<stdio.h>
#include"hotel.h"

int menu(void)                              //显示菜单并要求输入
{
    int code,status;

    printf("\n%s%s\n",STARS,STARS);
    printf("Enter the number of the desired hotel:\n");
    printf("1) Fairfield Arms         2) Hotel Olympic\n");
    printf("3) Chertworthy Plaza      4) The Stockton\n");
    printf("5) quit\n");
    printf("%s%s\n",STARS,STARS);
    while((status=scanf("%d",&code))!=1||
          (code<1||code>5))
    {
        if(status!=1)
            scanf("%*s");
        printf("Enter an integer from 1 to 5,please\n");
    }

    return code;
}

int getnights(void)                         //要求输入入住时长
{
    int nights;

    printf("How many nights are you needed?");
    while(scanf("%d",&nights)!=1)
    {
        scanf("%*s");
        printf("Please enter an integer,such as 2.\n");
    }

    return nights;
}

void showprice(double rate,int nights)      //显示总价
{
    int n;
    double total=0.0;
    double factor=1.0;

    for(n=1;n<=nights;n++,factor*=DISCOUNT)
        total+=rate*factor;
    printf("The hotel cost will be $%0.2f.\n",total);

    return;
}
