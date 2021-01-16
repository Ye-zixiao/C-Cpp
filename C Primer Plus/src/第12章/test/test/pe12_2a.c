#include<stdio.h>
static int mode;
static double distance;
static double fuel;

void set_mode(int get_mode)
{
	mode = get_mode;
	if (mode > 1)
	{
		printf("Invalid mode specified.Mode 1(US) used\n");
		mode = 1;
	}
}

void get_info(void)
{
	if (mode == 0)
	{
		printf("Enter distance traveled in kilometer: ");
		scanf("%lf", &distance);
		printf("Enter fuel traveled in liters: ");
		scanf("%lf", &fuel);
	}
	else if (mode == 1)
	{
		printf("Enter distance traveled in miles: ");
		scanf("%lf", &distance);
		printf("Enter fuel traveled in gallons: ");
		scanf("%lf", &fuel);
	}
}

void show_info(void)
{
	if (mode == 0)
		printf("Fuel consumption is %.2f liters per 100 km.\n", fuel * 100 / distance);
	else if (mode == 1)
		printf("Fuel consumption is %.2f miles per gallon.\n", distance / fuel);
}
