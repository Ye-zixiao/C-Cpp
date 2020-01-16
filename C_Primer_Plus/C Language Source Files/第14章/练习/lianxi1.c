#include<stdio.h>
#include<string.h>
#define MONTHS 12
#define LEN 20
#define ABBRLEN 4

typedef struct month {
	char monthname[LEN];
	char abbrname[ABBRLEN];
	int days;
	int day_aeq;
}YEAR_MONTH[MONTHS];

int before_days(YEAR_MONTH arr, char* st);

int main(void)
{
	YEAR_MONTH arr = {
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
	char name[LEN];
	int days;

	printf("Enter the name of the month: ");
	scanf("%s", name);
	if ((days = before_days(arr, name)) > 0)
		printf("Before the %s ,it has %d days.\n", name,days);
	else
		printf("You enter the wrong name of month.\n");

	return 0;
}

int before_days(YEAR_MONTH arr, char* st)
{
	int num;
	int sum = 0;
	int flag;

	for (num=0; num < MONTHS; num++)
	{
		if ((flag=strcmp(st, arr[num].monthname)) == 0)
			break;
	}
	//printf("num=%d\n", num);
	if (flag == 0)
	{
		int i;
		for (i = 0; i <= num; i++)
			sum += arr[i].days;
		return sum;
	}
	else
		return -1;
}
