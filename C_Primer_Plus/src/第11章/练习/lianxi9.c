#include<stdio.h>
#include<string.h>
#define SIZE 20
void change(char* str);

int main(void)
{
	char test[SIZE] = "love and share";
	change(test);
	puts(test);

	return 0;
}

void change(char* str)
{
	int times;
	int n;
	char temp;

	for (n = 0; n < strlen(str) / 2; n++)
	{
		temp = str[n];
		str[n] = str[strlen(str) - 1 - n];
		str[strlen(str) - 1 - n] = temp;
	}
}
