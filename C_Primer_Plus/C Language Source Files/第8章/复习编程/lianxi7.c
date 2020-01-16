//这就是典型的数值输入混合字符输入的典型,还可以改进
#include<stdio.h>
#define RATE1 8.75;
#define RATE2 9.33
#define RATE3 10.00
#define RATE4 11.20
#define BREAK1 300.0
#define BREAK2 450.0

#define TAX_RATE1 0.15
#define TAX_RATE2 0.20
#define TAX_RATE3 0.25

#define BASE1 (BREAK1*TAX_RATE1)
#define BASE2 (BASE1+TAX_RATE2*(BREAK2-BREAK1))
#define TIME_BREAK 40.0
#define OVERTIME_RATE 1.5

int main(void)
{
	char ch,ch1;
	double rate=0.0;
	double time;
	double wage;
	double tax;

	printf("Enter the character corresponding to the desired pay rate or action:\n");
	printf("a) $8.75/hr             b) $9.33/hr\n");
	printf("c) $10.00/hr            d) $11.20/hr\n");
	printf("q) quit\n");
	while ((ch = getchar()) != 'q')						//只提取首字母（abcdq）
	{
		switch (ch)
		{
			case '\n':
				continue;
			case 'a':
				rate = RATE1;
				break;
			case 'b':
				rate = RATE2;
				break;
			case 'c':
				rate = RATE3;
				break;
			case 'd':
				rate = RATE4;
				break;
			default:
				printf("Please enter the right form(alphabet)\n");
				while (getchar() != '\n')				//为了的是吃掉多余的字符
					continue;
				continue;
		}
		while (getchar() != '\n')						//为了的是吃掉多余的字符
			continue;

		printf("Enter the time that you work:\n");
		while (scanf("%lf", &time) != 1)				//吃掉字符，针对字符数值混合输入的情况
		{
			while ((ch1 = getchar()) != '\n')
				putchar(ch1);
			printf(" is not a number\n");
			printf("Please enter a number\n");
		}
		/*计算税金和收入*/
		if (time > TIME_BREAK)
			time = TIME_BREAK + (time - TIME_BREAK) * OVERTIME_RATE;

		wage = time * rate;
		if (wage <= BREAK1)
			tax = wage * TAX_RATE1;
		else if (wage <= BREAK2)
			tax = BASE1 + (wage - BREAK1) * TAX_RATE2;
		else
			tax = BASE2 + (wage - BREAK2) * 0.25;

		printf("You earn %0.2f dollars in this month,but the tax is %0.2f dollars,\n",
			wage, tax);
		printf("so you just earn %0.2f dollars in this month.\n", wage - tax);
		putchar('\n');

		printf("Enter the next character for this program\n");	//提示再一次输入
	}

	return 0;
}
