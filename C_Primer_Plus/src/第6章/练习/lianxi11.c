#include<stdio.h>
#define INT_NUM 8
int main(void)
{
	int i, j;
	int num[INT_NUM];

	printf("Please enter 8 numbers for this program:\n");
	for (i = 0; i < INT_NUM; i++)
		scanf("%d", &num[i]);

	for (j = INT_NUM - 1; j >= 0; j--)
		printf("%4d", num[j]);

	return 0;
}
