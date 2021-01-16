#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define SIZE 81
bool is_within(char* st, char ch);

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

	bool findc;
	findc =is_within(input, 'c');
	if (findc)
		puts("I find c");
	else
		puts("Not find c");

	return 0;
}

bool is_within(char* st, char ch)
{
	bool find=false;
	while (*st != ch && *st != '\0')
		st++;
	if (*st == ch)
		find = true;

	return find;
}

bool is_with2(char *st,char ch)
{
    while(*st!=ch&&*st!='\0')
        st++;

    return *st;//用指针的解引用来作为测试条件
}
