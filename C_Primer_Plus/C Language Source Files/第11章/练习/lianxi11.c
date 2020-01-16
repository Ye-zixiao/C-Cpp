#include<stdio.h>
#include<string.h>
#define SIZE 81
#define LIM 5

char* s_gets(char* st, int n);
void sort_ascii(char* st[], int n);

int main(void)
{
	char input[LIM][SIZE];
	char* ptr[LIM];
	int ct = 0;
	while (s_gets(input[ct], SIZE) != NULL && ct < LIM && input[ct][0] != EOF)
	{
		ptr[ct] = input[ct];
		ct++;
	}
	sort_ascii(ptr, ct);//输入多少行就有多少行
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

void sort_ascii(char* st[], int n)
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
	int i ;
	for (i=0; i < n; i++)
		puts(st[i]);
}
