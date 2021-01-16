#include<stdio.h>
void trystat(void);

int main(void)
{
	int count;

	for (count = 1; count <= 3; count++)
	{
		printf("Here comes iteration %d\n", count);
		trystat();
	}

	return 0;
}

void trystat(void)
{
	int fade = 1;
	static int stay = 1;//程序只会对它初始化一次，下一次执行的时候会自动的跳过这个语句，可以用逐句执行检查

	printf("fade=%d and stay=%d\n", fade++, stay++);
}
