#include<stdio.h>
void alter(int* px, int* py);

int main(void)
{
	int x = 3;
	int y = 6;

	printf("Originally,x=%d and y=%d\n", x, y);
	alter(&x, &y);
	printf("Now,x=%d and y=%d\n", x, y);

	return 0;
}

void alter(int* px, int* py)
{
	int temp;
	temp = *px + *py;
	*py = *px - *py;
	*px = temp;
}
