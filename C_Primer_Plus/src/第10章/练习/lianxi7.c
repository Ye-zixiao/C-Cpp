#include<stdio.h>
#define COLS 4
void copy(double(*arr1)[COLS], const double(*arr2)[COLS], int n);
void show2d(const double (*arr)[COLS], int n);

int main(void)
{
	double arr[3][COLS] = { {4.1,3.2,5.2,6.1},
	{5.1,9.8,9.3,7.6},{5.2,3.1,6.9,7.4} };
	double target[3][COLS];
	show2d(arr, 3);
	putchar('\n');

	copy(target, arr, 3);
	show2d(target, 3);
	putchar('\n');

	return 0;
}

void show2d(const double(*arr)[COLS], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < COLS; j++)
			printf("%0.2f ", *(*(arr + i) + j));
		putchar('\n');
	}
}

void copy(double(*arr1)[COLS], const double(*arr2)[COLS], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < COLS; j++)
			arr1[i][j] = arr2[i][j];
}
