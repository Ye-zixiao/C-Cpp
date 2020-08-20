#include<stdio.h>
void chline(char, int, int);

int main(void)
{
	char ch = 'A';
	int num1, num2;

	printf("Please enter two numbers for this program\n");
	scanf("%d %d", &num1, &num2);
	chline(ch, num1,num2);
	putchar('\n');
	return 0;
}

void chline(char ch, int i, int j)
{
    int m;
	for ( m = 1; m <= j; m++)
	{
	    int n;
		for (n = 1; n <= i; n++)
			putchar(ch);
		putchar('\n');
	}
	return;
}
