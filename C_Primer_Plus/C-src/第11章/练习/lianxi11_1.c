#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 81
#define LIM 5

char* s_gets(char* st, int n);
void sort_ascii(char* st[], int n);
void initial(char* st[], int n);
void sort_length(char* st[], int n);
void sort_first(char* st[]);
void menu3(void);

int main(void)
{
	char input[LIM][SIZE];
	char* ptr[LIM];
	int ct = 0;
	puts("Enter the strings for this program:");
	while (s_gets(input[ct], SIZE) != NULL && ct < LIM && input[ct][0] != EOF)
	{
		ptr[ct] = input[ct];
		ct++;
	}
	char ch;
	menu3();
	while ((ch = getchar()) != 'q')
	{
		if (ch == '\n')
			continue;
		switch (ch)
		{
		case 'a':
			initial(ptr, ct);
			break;
		case 'b':
			sort_ascii(ptr, ct);
			break;
		case 'c':
			sort_length(ptr, ct);
			break;
		case 'd':
			sort_first(ptr);
			break;
		default:
			break;
		}
		menu3();
	}
	puts("Done.");

	return 0;
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

void menu3(void)
{
	puts("Enter a character for this program");
	puts("a) print initially            b) print in ascii");
	puts("c) print in the length        d) print in the length of first word");
	puts("q) quit");
}

void sort_ascii(char* st[], int n)			//以ascii码排序
{
	char* temp;
	int top, seek;

	for (top = 0; top < n - 1; top++)
		for (seek = top + 1; seek < n; seek++)
			if (strcmp(st[top], st[seek]) > 0)
			{
				temp = st[seek];
				st[seek] = st[top];
				st[top] = temp;
			}
	int i;
	for (i = 0; i < n; i++)
		puts(st[i]);
}

void initial(char* st[], int n)				//原始输出,缺点：原始数组会因为其他选项而改变
{
	int i;
	for (i = 0; i < n; i++)
		puts(st[i]);
}

void sort_length(char* st[], int n)			//以长度排序
{
	char* temp;
	int top, seek;
	for (top = 0; top < n - 1; top++)
		for (seek = top + 1; seek < n; seek++)
			if (strlen(st[top]) > strlen(st[seek]))
			{
				temp = st[top];
				st[top] = st[seek];
				st[seek] = temp;
			}
	int i;
	for (i = 0; i < n; i++)
		puts(st[i]);
}

void sort_first(char* st[])				//首单词长度排序
{
	char word[4][10];
	char* pword[4];
	int i;
	int ct = 0;

	for (i = 0; i < 4; i++)
	{
		pword[i] = word[i];
		while (isspace(*st[i]) || ispunct(*st[i]))
		{
			st[i]++;
		}
		while (isalpha(*st[i]) && ct < 9)
		{
			*pword[i] = *st[i];
			st[i]++;
			pword[i]++;
			ct++;
		}
		*pword[i] = '\0';
	}

	char* temp;
	int top, seek;
	for (top = 0; top < 4 - 1; top++)
		for (seek = top + 1; seek <4; seek++)
			if (strlen(word[top]) > strlen(word[seek]))
			{
				temp = pword[top];
				pword[top] = pword[seek];
				pword[seek] = temp;

				temp = st[top];
				st[top] = st[seek];
				st[seek] = temp;
			}
	for (i = 0; i < 4; i++)
		puts(st[i]);
}
