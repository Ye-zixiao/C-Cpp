#include<stdio.h>
#define FUCK_TIME_RATE 1.5
#define RATE_1 0.15
#define RATE_2 0.2
#define RATE_3 0.25
#define BREAK_1 300.0
#define BREAK_2 450.0
#define BASE_1 (BREAK_1*RATE_1)
#define BASE_2 (BASE_1+(BREAK_2-BREAK_1)*RATE_2)
#define TIME_BREAK 40

int main(void)
{
	char ch;
	float hourly_wage;
	int work_time, fuck_time;
	float wage, net_income, tax;

	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("1) $8.75/hr                         2) $9.33/hr\n");
	printf("3) $10.00/hr                        4) $11.20/hr\n");
	printf("5) quit\n");
	while ((ch = getchar()) != '5')
	{
		switch (ch)
		{
		case '1':
			hourly_wage = 8.75;
			break;
		case '2':
			hourly_wage = 9.33;
			break;
		case '3':
			hourly_wage = 10.00;
			break;
		case '4':
			hourly_wage = 11.20;
			break;
		case '\n':
			continue;			//这个continue是为了吃掉一个回车符
		default:
			printf("Please enter the right form for this program:\n");
			continue;
		}
		printf("Now,your hourly_wage is $%0.2f.\n", hourly_wage);

		printf("Enter the time(hr) you work for your company:\n");
		scanf("%d", &work_time);
		if (work_time > TIME_BREAK)
		{
			fuck_time = work_time - TIME_BREAK;
			fuck_time *= FUCK_TIME_RATE;
			work_time = fuck_time + TIME_BREAK;
		}
		wage = hourly_wage * work_time;
		if (wage <= BREAK_1)
			tax = RATE_1 * wage;
		else if (wage > BREAK_1 && wage <= BREAK_2)
			tax = BASE_1 + RATE_2 * (wage - BREAK_1);
		else
			tax = BASE_2 + RATE_3 * (wage - BREAK_2);
		net_income = wage - tax;

		printf("wage=%0.2f,tax=%0.2f,net_income=%0.2f.\n", wage, tax, net_income);
		printf("Please keep choicing the hourly_wage for this program：\n\n");
	}
	printf("Done.\n");

	return 0;
}
