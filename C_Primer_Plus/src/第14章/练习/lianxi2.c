#include<stdio.h>
#include<stdio.h>
#define MONTHS 12
#define ABBRLEN 4
#define LEN 20

typedef struct month {
	char monthname[LEN];
	char monthabbr[ABBRLEN];
	int days;
	int serial_num;
}YEAR_MONTH[MONTHS];

int before_days(YEAR_MONTH arr, char* st, int days);

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
	int day;
	char mon[LEN];
	int year;
	int value;

	printf("Enter year: ");
	scanf("%d", &year);
	printf("Enter month: ");
	scanf("%s", mon);
	printf("Enter the day of the month: ");
	scanf("%d", &day);
	if ((value = before_days(arr, mon, day)) > 0)
		printf("Before that day,it has %d days.\n", value);
	else
		printf("Error input.\n");

	return 0;
}

int before_days(YEAR_MONTH arr, char* st, int days)
{
	int num;
	int i;
	int sum = 0;
	int flag;

	for (num = 0; num < MONTHS; num++)
	{
		if((flag=strcmp(st,arr[num].monthname))==0)
			break;
	}
	if (flag == 0)
	{
		for (i = 0; i < num; i++)
			sum += arr[i].days;
		return sum+days;
	}
	else
		return -1;
}
