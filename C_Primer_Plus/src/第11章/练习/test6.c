#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define ANSWER "GRANT"
char* s_gets(char* st, int n);
void Upper(char* st);

int main(void)
{
	char try[81];

	puts("Who is buried in Grant's tomb?");
	s_gets(try, 81);
	Upper(try);
	while (strcmp(try, ANSWER))
	{
		puts("No,that's wrong.Try again.");
		s_gets(try, 81);
	}
	puts("You are right.");

	return 0;
}

void Upper(char* st)
{
	while (*st != '\0')
	{
		*st=toupper(*st);
		st++;
	}
}

char* s_gets(char* st, int n)
{
	char* ret_val;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		char* find;
		find = strchr(st, '\n');
		if (find)
			* find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
