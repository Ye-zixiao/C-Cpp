#include<stdio.h>
#include<string.h>

void drop_space(char* st);
char* s_gets(char* st, int n);

int main(void)
{
	char input[81];
	s_gets(input, 81);
	puts(input);
	drop_space(input);
	puts(input);

	return 0;
}

void drop_space(char* st)
{
	char* forswap;
	while (*st)
	{
		if (*st == ' ')
		{
			forswap = st;
			do
			{
				*forswap = *(forswap + 1);
				forswap++;
			} while (*forswap);
		}
		else
			st++;
	}
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
