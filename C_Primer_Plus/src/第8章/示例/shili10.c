/* 对书中P236、237、238、239的程序的修改3：基本解决了scanf函数输入数字带来的换行符问题，
对count函数不能处理非数字字符的问题，自己修改，只是借鉴了修改2的思想*/
#include<stdio.h>
char get_choice(void);
void count(void);
char get_first(void);

int main(void)
{
	char choice;

	printf("Please choice: \n");
	while ((choice = get_choice()) != 'q')
	{
		switch (choice)
		{
		case 'a':
			printf("Buy low,sell high.\n");
			break;
		case 'b':
			putchar('\a');
			break;
		case 'c':
			count();
			break;
		case '\n':
			printf("Program error.\n");
			break;
		}
		printf("Rechoice:\n");
	}
	printf("Done.\n");

	return 0;
}

char get_choice(void)
{
	char ch;

	printf("Enter the letter of your choice:\n");
	printf("a) advice           b) bell\n");
	printf("c) count            q) quit\n");
	ch = get_first();
	while ((ch<'a' || ch>'c') && ch != 'q')
	{
		printf("Please respond with a,b,c, or q.\n");
		ch = get_first();
	}

	return ch;
}

void count(void)
{
	int n, i;
	printf("Count how far?Enter an integer:\n");
	while (scanf("%d", &n) != 1)
	{
		while (getchar() != '\n')
			continue;
		printf("What you input is not correct.\n");
		printf("Try again: ");
	}
	for (i = 1; i <= n; i++)
		printf("%d\n", i);
}

char get_first(void)
{
	char ch;

	while ((ch = getchar()) == '\n')			/*判断第一个输入是否为换行符，若是再次读取，直到读取的不是换行符*/
		continue;

	while (getchar() != '\n')
		continue;

	return ch;
}
