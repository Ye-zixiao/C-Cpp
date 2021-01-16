#include<stdio.h>
#include<string.h>
#define SIZE 81
char* find(char* st, char ch);

int main(void)
{
	char input[SIZE];
	char* ptr=input;
	char ch;
	int ct = 0;

	while ((ch = getchar()) != '\n'&&ct<=SIZE-1)
	{
		*ptr = ch;
		ptr++;
		ct++;
	}
	*ptr = '\0';

	char* findc;
	findc = find(input, 'c');
	if (findc)
		puts("I find c");
	else
		puts("Not find c");

	return 0;
}

char* find(char* st, char ch)
{
	char* find=NULL;
	while (*st != ch && *st != '\0')
		st++;
	if (*st == ch)
		find = st;

	return find;
}
