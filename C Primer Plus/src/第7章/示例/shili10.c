#include <stdio.h>
int main(void)
{
	const float MIN = 0.0f;
	const float MAX = 100.0f;

	float scores;
	float total = 0.0f;
	int n = 0;
	float min = MAX;
	float max = MIN;

	printf("Enter the first scores(q to quit this program)\n");
	while (scanf("%f", &scores) == 1)
	{
		if (scores<0.0 || scores>100.0)
		{
			printf("%0.1f is an invalid value.Try again:\n", scores);
			continue;
		}

		printf("Accepting %0.1f:\n", scores);
		min = (scores < min) ? scores : min;
		max = (scores > max) ? scores : max;
		total += scores;
		n++;
		printf("Enter next scores (q to quit this program).\n");
	}
	if (n > 0)
	{
		printf("Average of %d scores is %0.1f.\n", n, total / n);
		printf("Low =%0.1f,hign=%0.1f ,\n", min, max);
	}
	else
		printf("No valid data entered.\n");

	return 0;
}
