#include<stdio.h>
#include<stdlib.h>
#define SIZE 4

double sum(double x, double y);
double differ(double x, double y);
double multiple(double x, double y);
double division(double x, double y);
void menu(void);
double (*pf[SIZE])(double, double);

int main(void)
{
	pf[0] = sum;
	pf[1] = differ;
	pf[2] = multiple;
	pf[3] = division;
	double num1, num2;

	printf("Enter two floating number for this program.\n");
	scanf("%lf %lf", &num1, &num2);
	char ch;
	double value=0.0;
	menu();
	getchar();
	while ((ch = getchar()) != 'e')
	{
		switch (ch)
		{
			case 'a':value =(*pf[0])(num1, num2); break;
			case 'b':value = (*pf[1])(num1, num2); break;
			case 'c':value = (*pf[2])(num1, num2); break;
			case 'd':value = (*pf[3])(num1, num2); break;
		}
		printf("value=%.2f.\n",value);
		while (getchar() != '\n')
			continue;
		menu();
	}
	puts("Done.");

	return 0;
}

void menu(void)
{
	puts("chooice the following one:");
	puts("a) sum");
	puts("b) differ");
	puts("c) multiple");
	puts("d) division");
	puts("e) exit");
}

double sum(double x, double y)
{
	return x + y;
}

double differ(double x, double y)
{
	return x - y;
}

double multiple(double x, double y)
{
	return x * y;
}

double division(double x, double y)
{
	return x / y;
}
