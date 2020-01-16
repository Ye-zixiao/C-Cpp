#include <stdio.h>
int main(void)
{
	int num, i, j;
	_Bool isprime;

	printf("Please enter the number for this program\n");
	while (scanf("%d", &num) && num > 0)
	{
		if (num > 1)
		{
			printf("Prime are as follows:\n");
			for (i = 2; i <= num; i++)			//单纯这个语句是不会对1进行判断的，因为1连for循环体都进不去。所以要对1单独判断
			{
				for (j = 2, isprime = 1; j * j <= i; j++)
				{
					if (i % j == 0)
					{
						isprime = 0;			//说明它不是素数
						break;					//跳出循环
					}
				}
				if (isprime)					//将每一个素数打印
					printf("%4d", i);
			}
		}
		else
	 		printf("There is no prime\n");
		printf("\n");
	}
	printf("Done\n");

	return 0;
}
