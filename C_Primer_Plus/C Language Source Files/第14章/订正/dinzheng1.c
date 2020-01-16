#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MONTHS 12
#define LEN 20
#define ABBRLEN 4

typedef struct month {
	char monthname[LEN];
	char abbrname[ABBRLEN];
	int days;
	int day_seq;
}YEAR_MONTH[MONTHS];

const YEAR_MONTH arr= {
	{"January","Jan", 31, 1},
	{"February","Feb", 28, 2},
	{"March","Mar", 31, 3},
	{"April","Apr", 30, 4},
	{"May","May", 31, 5},
	{"June","Jun", 30, 6},
	{"July","Jul", 31, 7},
	{"August","Aug", 31, 8},
	{"September","Sep", 30, 9},
	{"October","Oct", 31, 10},
	{"November","Nov", 30, 11},
	{"December","Dec", 31, 12}
};

int before_days(char* st);
char* s_gets(char* st, int n);

int main(void)
{
	char input[LEN];
	printf("Enter the name of month that you want: ");
	while (s_gets(input, LEN) != NULL && input[0] != '\0')
	{
		int value;
		if ((value = before_days(input)) > 0)
			printf("Though month %s,it has %d days.\n", input, value);
		else
			printf("You input invalid data.\n");
		printf("Enter the next name of month(enter [enter] to quit)");
	}

	puts("Done");

	return 0;
}

int before_days(char* st)
{
	int sum = 0;
	int num = 0;
	int i;

	st[0] = toupper(st[0]);
	for (i = 1; st[i] != '\0'; i++)
		st[i] = tolower(st[i]);
	for (i = 0; i < MONTHS; i++)
	{
		if (strcmp(st, arr[i].monthname) == 0)
		{
			num = i+1;
			break;
		}
	}
	if (num == 0)
		return -1;
	else
		for (i = 0; i < num; i++)
			sum += arr[i].days;
	return sum;
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			* find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
