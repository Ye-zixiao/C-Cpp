#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

typedef struct {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
}book;
char* s_gets(char* st, int n);
void sortvalue(book* arr, int n);
void sorttitle(book* arr, int n);

int main(void)
{
	book arr[MAXBKS];
	int i;
	int count = 0;

	printf("Enter the book title(enter [enter] to quit): ");
	while (count < MAXBKS && s_gets(arr[count].title, MAXTITL) != NULL && arr[count].title[0] != '\0')
	{
		printf("Now enter the author for this book: ");
		s_gets(arr[count].author, MAXAUTL);
		printf("Now enter the value: ");
		scanf("%f", &arr[count++].value);
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			printf("Please enter the title of next book: ");
	}

	if (count > 0)
	{
		printf("Here are the list of your input book:\n");
		for (i = 0; i < count; i++)
			printf("%s by %s: $%.2f.\n", arr[i].title, arr[i].author, arr[i].value);

		sorttitle(arr, count);
		printf("Here are the list of your input book after title sorting:\n");
		for (i = 0; i < count; i++)
			printf("%s by %s: $%.2f.\n", arr[i].title, arr[i].author, arr[i].value);

		sortvalue(arr, count);
		printf("Here are the list of your input book after value sorting:\n");
		for (i = 0; i < count; i++)
			printf("%s by %s: $%.2f.\n", arr[i].title, arr[i].author, arr[i].value);
	}
	puts("Done");

	return 0;
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

void sortvalue(book* arr, int n)
{
	int i, j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if (arr[i].value > arr[j].value)
			{
				book temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
}

void sorttitle(book* arr, int n)
{
	int i, j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if (arr[i].title[0] > arr[j].title[0])
			{
				book temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
}
