#include<stdio.h>

double get_info(int mode)
{
    double distance;
    double fuel;

    if(mode==0)
    {
        printf("Enter distance traveled in kilometer: ");
        scanf("%lf",&distance);
        printf("Enter fuel traveled in liters: ");
        scanf("%lf",&fuel);

        return fuel*100/distance;
    }
    else if(mode>=1)
    {
        if(mode>1)
            printf("Invalid mode specified.Mode 1(US) used.\n");
        printf("Enter distance traveled in miles: ");
        scanf("%lf",&distance);
        printf("Enter fuel traveled in gallons: ");
        scanf("%lf",&fuel);

        return distance/fuel;
    }
}

void show_info(double result,int mode)
{
    if(mode==0)
        printf("Fuel consumption is %.2f liters per 100 km.\n",result);
    else if(mode>=1)
        printf("Fuel consumption is %.2f miles per gallon.\n",result);
}
