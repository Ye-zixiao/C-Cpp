#include<stdio.h>
unsigned int rand0(void);

int main(void)
{
	int ct;
	for (ct = 0; ct < 5; ct++)
		printf("%d\n", rand0());

	return 0;
}