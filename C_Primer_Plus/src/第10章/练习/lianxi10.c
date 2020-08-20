#include<stdio.h>
void proccess(double *arr1, double *arr2, double *arr3, int n);
void show_arr(const double *arr, int n);

int main(void)
{
	double arr1[4] = { 2.0,4.0,5.0,8.0 };
	double arr2[4] = { 1.0,0.0,4.0,6.0 };
	double arr3[4];
	printf("this is arr1:\n");
	show_arr(arr1, 4);
	putchar('\n');
	printf("this is arr2:\n");
	show_arr(arr2, 4);
	putchar('\n');

	proccess(arr3, arr1, arr2, 4);
	printf("this is arr3:\n");
	show_arr(arr3, 4);
	putchar('\n');

	return 0;
}

void proccess(double *arr1, double *arr2, double *arr3, int n)
{
	int i;
	for (i = 0; i < n; i++)
		* (arr1 + i) = *(arr2 + i) + *(arr3 + i);
}

void show_arr(const double *arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%0.1f ", arr[i]);
}
