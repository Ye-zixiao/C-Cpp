/* 对书中P236、237、238、239的程序的修改2（这是书上的源程序）：基本解决了scanf函数输入数字带来的换行符问题，
解决了count函数不能处理非数字字符的问题，但对于我而言：程序过于冗长*/
#include<stdio.h>
char get_choice(void);
void count(void);
char get_first(void);
int get_int(void);

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
	printf("Count how far? Enter an integer:\n");
	n=get_int();
	for (i = 1; i <= n; i++)
		printf("%d\n", i);
	while (getchar() != '\n')					//吃掉scanf()函数输入数字+回车引入的换行符'\n'
		continue;
}

char get_first(void)
{
	char ch;

	ch = getchar();
	while (getchar() != '\n')
		continue;

	return ch;
}

int get_int(void)
{
	int input;
	char ch;

	while (scanf("%d", &input) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not an integer.\nPlease enter an ");
		printf("integer value, such as 25, -178, or 3: ");
	}

	return input;
}
