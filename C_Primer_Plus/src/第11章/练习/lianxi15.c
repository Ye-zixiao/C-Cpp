#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<ctype.h>
#define msg "18abc"
#define SIZE 10
int atoi(char* st, int n);

int main(void)
{
	char arr[SIZE] = msg;
	printf("ret_val=%d\n", atoi(arr, SIZE));

	return 0;
}

int atoi(char* st, int n)
{
	int ret_val = 0;
	int ct = 0;
	bool flag = false;
	while (isdigit(st[ct]) && st[ct] != '\0')
	{
		ct++;
		flag = true;
	}
	if (flag)
	{
		int i;
		for (i = 0; i < ct; i++)
		{
			printf("%d\n", ((int)st[i] - 48) * (int)pow(10, ct - i - 1));
			ret_val += ((int)st[i] - 48) * (int)pow(10, ct - i - 1);
		}
	}
	return ret_val;
}

