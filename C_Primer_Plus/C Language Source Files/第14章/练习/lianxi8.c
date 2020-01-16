#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define	LEN 20
#define SIZE 5

struct name {
	char fname[LEN];
	char lname[LEN];
};

typedef struct airplane {
	unsigned int num;
	bool book_flag;
	struct name member;
}Airplane;

void menu(void);
void show_empty_num(Airplane* arr, int n);
void show_empty_list(Airplane* arr, int n);
void show_alpha_list(Airplane* arr, int n);
bool assign_seat(Airplane* arr, int n);
bool delete_seat(Airplane* arr, int n);

int main(void)
{
	Airplane arr[SIZE] = {
		{10012001,false,"\0","\0"},
		{10012002,false,"\0","\0"},
		{10012003,false,"\0","\0"},
		{10012004,false,"\0","\0"},
		{10012005,false,"\0","\0"}
	};
	char ch;
	menu();
	while ((ch = getchar()) != 'f')
	{
		switch (ch)
		{
			case 'a':show_empty_num(arr, 5); break;
			case 'b':show_empty_list(arr,5); break;
			case 'c':show_alpha_list(arr,5); break;
			case 'd':assign_seat(arr, 5); break;
			case 'e':delete_seat(arr, 5); break;
		}
		while (getchar() != '\n')
			continue;
		menu();
	}
	puts("Done.\n");

	return 0;
}

void menu(void)
{
	puts("To choose a function ,enter its letter label:");
	puts("a) Show number of empty seats");
	puts("b) Show list of empty seats");
	puts("c) Show alphabetical list of seats");
	puts("d) Assign a customer to a seat assignment");
	puts("e) Delete a seat assignment");
	puts("f) Quit");
}

void show_empty_num(Airplane* arr, int n)
{
	int i;
	int empty_num = 0;
	for (i = 0; i < n; i++)
	{
		if (!arr[i].book_flag)
			empty_num++;
	}
	printf("We have %d empty seat(s).\n",empty_num);
}

void show_empty_list(Airplane* arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (!arr[i].book_flag)
			printf("seat %u ", arr[i].num);
	}
	printf("is empty.\n");
}

void show_alpha_list(Airplane* arr, int n)
{
	int i, j;
	for(i=0;i<n-1;i++)
		for (j = i + 1; j < n; j++)
		{
			if(arr[i].book_flag&&arr[j].book_flag)
				if (arr[i].member.fname[0] > arr[j].member.fname[0])
				{
					unsigned int temp = arr[i].num;
					arr[i].num = arr[j].num;
					arr[j].num = temp;

					char tempname[LEN];
					strcpy(tempname, arr[i].member.fname);
					strcpy(arr[i].member.fname, arr[j].member.fname);
					strcpy(arr[j].member.fname, tempname);

					strcpy(tempname, arr[i].member.lname);
					strcpy(arr[i].member.lname, arr[j].member.lname);
					strcpy(arr[j].member.lname, tempname);
				}
		}

	for (i = 0; i < n; i++)
	{
		if (arr[i].book_flag)
			printf("%s %s books seat %u.\n", arr[i].member.fname, arr[i].member.lname, arr[i].num);
	}
}

bool assign_seat(Airplane* arr, int n)
{
	int seat_num = 0;
	int i=0;
	while (i < n)
	{
		if (!arr[i].book_flag)
			seat_num++;
		i++;
	}
	if (seat_num == 0)
		return false;
	else
	{
		i = 0;
		while (i < n)
		{
			if (!arr[i].book_flag)
				break;
			i++;
		}
		printf("Enter your first name: ");
		scanf("%s", arr[i].member.fname);
		printf("Enter your last name: ");
		scanf("%s",arr[i].member.lname);
		arr[i].book_flag = true;
		printf("Assign success.\n");
		return true;
	}
}

bool delete_seat(Airplane* arr, int n)
{
	char nametemp[LEN];
	printf("Enter your first name: ");
	scanf("%s", nametemp);
	int i;
	int flag;
	for (i = 0; i < n; i++)
	{
		if ((flag = strcmp(nametemp, arr[i].member.fname))== 0)
			break;
	}
	if (flag == 0)
	{
		printf("I will delete your booking.\n");
		if (arr[i].book_flag == false)
		{
			printf("Sorry,you hadn't booked.\n");
			return false;
		}
		else
		{
			arr[i].book_flag = false;
			printf("Deleted!\n");
			return true;
		}
	}
	else
	{
		printf("System can't find your name.\n");
		return false;
	}
}
