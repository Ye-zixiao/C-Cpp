#include<stdio.h>
#define SIZE 8
int main(void)
{
	double num1[SIZE], num2[SIZE];
	double sum;
	int i, j;

	printf("Enter the eight numbers for this program:\n");
	for (i = 0; i < SIZE; i++)
	{
		scanf("%lf", &num1[i]);
		for (j = 0, sum = 0; j <= i; j++)
		{
			sum += num1[j];
		}
		num2[i] = sum;
	}

	for (i = 0; i < SIZE; i++)
		printf("%8.2f", num1[i]);
	printf("\n");
	for (i = 0; i < SIZE; i++)
		printf("%8.2f", num2[i]);
	printf("\n");

	return 0;
}
