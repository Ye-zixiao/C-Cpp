#include<stdio.h>
#include"fuzhu2.h"

void check_mode(int *mode)
{
    if(*mode!=metric&&*mode!=US)
    {
        printf("Invalid mode specified.Previous mode used.\n");
        *mode=PRE_MODE;
    }
}

void get_info(int mode,double *distance,double *fuel)
{
    if(mode==metric)
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf",distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf",fuel);
    }
    else
    {
        printf("Enter distance traveled in miles: ");
        scanf("%lf",distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf",fuel);
    }
}

void show_info(int mode,double distance,double fuel)
{
    if(mode==metric)
        printf("Fuel consumption is %0.1f liters per 100 km.\n",fuel*100/distance);
    else
        printf("Fuel consumption is %0.1f miles in per gallon.\n",distance/fuel);
}
