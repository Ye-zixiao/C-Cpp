#include<stdio.h>
#define COLS 5
void change(int(*arr)[COLS], int n);
void show_arr(const int(*arr)[COLS], int n);

int main(void)
{
	int arr[3][COLS] = { {1,5,6,7,9},{4,6,5,3,2},{4,2,3,1,5} };
	printf("This is array before the change:\n");
	show_arr(arr, 3);
	putchar('\n');

	change(arr, 3);
	printf("This is the array after changing:\n");
	show_arr(arr, 3);
	putchar('\n');

	return 0;
}

void change(int(*arr)[COLS], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < COLS; j++)
			arr[i][j] *= 2;
}

void show_arr(const int(*arr)[COLS], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < COLS; j++)
			printf("%d ", arr[i][j]);
		putchar('\n');
	}
}
