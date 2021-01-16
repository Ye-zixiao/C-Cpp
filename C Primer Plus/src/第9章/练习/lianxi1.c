#include<stdio.h>
double min(double, double);

int main(void)
{
	double x = 1.5;
	double y = 5.4;
	double temp;

	printf("x=%.2f and y=%.2f\n", x, y);
	temp = min(x, y);
	printf("The mininum is %0.2f between this two floatings\n", temp);

	return 0;
}

double min(double x, double y)
{
	return x > y ? y : x;
}
