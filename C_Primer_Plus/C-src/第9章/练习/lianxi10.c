#include<stdio.h>
#define ulong unsigned long
void to_base(ulong m, int n);

int main(void)
{
	ulong num;
	int n;

	printf("Enter two numbers for this program:\n");
	while (scanf("%lu %d", &num, &n) == 2)
	{
		printf("It's another form is:");
		to_base(num, n);
		printf("\n");
		printf("Enter two numbers for this program again:\n");
	}
	printf("Done\n");

	return 0;

}

void to_base(ulong num, int n)
{
	int r;

	r = num % n;
	num = num / n;
	if (num > 0)
		to_base(num, n);
	printf("%d", r);
}
