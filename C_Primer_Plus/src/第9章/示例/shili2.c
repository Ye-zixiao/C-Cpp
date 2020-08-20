#include<stdio.h>
#include<string.h>
#define NAME "GIGATHINK, INC"
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40
#define SPACE ' '
void show_n_char(char ch, int n);

int main(void)
{
	show_n_char('*', WIDTH);
	putchar('\n');

	show_n_char(SPACE, (WIDTH - strlen(NAME)) / 2);//打印（一行的字符容量减去地址长度）的一半
	printf("%s\n", NAME);

	show_n_char(SPACE, (WIDTH - strlen(ADDRESS)) / 2);
	printf("%s\n", ADDRESS);

	show_n_char(SPACE, (WIDTH - strlen(PLACE) )/ 2);
	printf("%s\n", PLACE);

	show_n_char('*', WIDTH);
	putchar('\n');

	return 0;
}

void show_n_char(char ch,int num)
{
	int count;
	for (count = 1; count <= num; count++)
		putchar(ch);
}
