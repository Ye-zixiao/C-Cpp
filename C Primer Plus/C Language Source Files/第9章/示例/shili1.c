#include<stdio.h>
#define NAME "GIGATHINK, INC"
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40
void starbur(void);

int main(void)
{
	starbur();
	printf("%s\n", NAME);
	printf("%s\n", ADDRESS);
	printf("%s\n", PLACE);
	starbur();

	return 0;
}

void starbur(void)
{
	int count;
	for (count = 1; count <= WIDTH; count++)
		putchar('*');
	putchar('\n');
}
