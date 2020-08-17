#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;

	while (isspace(ch = getchar()))
		continue;
	putchar(ch);
	putchar('\n');

	return 0;
}
