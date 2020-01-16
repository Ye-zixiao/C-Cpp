#include<stdio.h>
int main(void)
{
	int num, i;
	double sum1, sum2;

	printf("Enter a number for this program:\n");
	while (scanf("%d", &num), num > 0)          /*为什么这里while判断语句中加入了两个表达式却没有关系
                                                    ：因为while只判断右边的表达式，而逗号是序列点，所以程序是从左往右进行的*/
	{
		for (i = 1, sum1 = 0; i <= num; i++)
			sum1 += 1.0 / i;
		printf("the sum1=%.3f\n", sum1);

		for (i = 1, sum2 = 0; i <= num; i++)
		{
			if (i % 2 == 1)                     //用模的方法判断奇偶最合适不过
				sum2 += 1.0 / i;
			else
				sum2 -= 1.0 / i;
		}
		printf("the sum2=%.3f\n", sum2);
	}

	return 0;
}
