#include<stdio.h>
int main(void)
{
	int even_count = 0, odd_count = 0;
	double even_sum=0, odd_sum=0;
	int num;

	printf("Please enter the numbers for this program\n");
	printf("(enter the 0 to quit)\n");
	while (scanf("%d", &num) && num != 0)
	{
		if (num % 2 == 0)
		{
			even_count++;
			even_sum += num;
		}
		else
		{
			odd_count++;
			odd_sum += num;
		}
	}
	printf("even_count=%d\n", even_count);
	if (even_count > 0)
		printf("even_average=%0.2f\n", even_sum / even_count);
	else
		printf("even_average is 0\n");

	printf("odd_count=%d\n", odd_count);
	if (odd_count > 0)
		printf("odd_average=%0.2f\n",odd_sum / odd_count);
	else
		printf("odd_average is 0\n");

	return 0;
}
