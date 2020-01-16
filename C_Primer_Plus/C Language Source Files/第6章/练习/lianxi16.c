#include <stdio.h>
double Daphne(int x);
double Deirdre(int y);
#define MONEY 100.0
#define RATE_1 0.1
#define RATE_2 0.05

int main(void)
{
	int years = 0;
	double sum_1, sum_2;
	sum_1 = 0;
	sum_2 = 0;

	do
	{
		years++;
		sum_1 = Daphne(years);
		sum_2 = Deirdre(years);
	}
	while (sum_1 >sum_2);
	printf("The years that Deirdre needs is %d years to exceed Daphne,\n", years);
	printf("In this year,Daphne posseses $%.2f .\n", sum_1);
	printf("In this year,Deirdre posseses $%.2f .\n", sum_2);

	return 0;
}

double Daphne(int x)
{
	double zeng = 100 * RATE_1;
	return MONEY + zeng * x;
}

double Deirdre(int y)
{
	int i;
	double sum2=MONEY;

	for (i = 1; i <= y; i++)
		sum2 *= (RATE_2 + 1);

	return sum2;
}
