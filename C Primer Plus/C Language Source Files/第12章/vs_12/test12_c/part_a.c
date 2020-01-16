#include<stdio.h>
extern void accumulate(int k);//外部函数表示函数定义在别的翻译文件当中
static void report_ct(void);//静态函数只能在当前翻译文件中寻找函数定义

int count = 0;

int main(void)
{
	int value;
	register int i;

	printf("Enter a positive integer (0 to quit): ");
	while (scanf_s("%d", &value) == 1 && value > 0)
	{
		count++;
		for (i = value; i >= 0; i--)
			accumulate(i);
		printf("Enter a positive integer (0 to quit): ");
	}
	report_ct();

	return 0;
}

void report_ct(void)
{
	printf("%d\n", count);
}