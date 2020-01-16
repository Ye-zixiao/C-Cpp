#include<stdio.h>
#include<stdbool.h>
long get_long(void);
bool bad_limits(long begin, long end, long low, long high);
double sum_squares(long a, long b);

int main(void)
{
	const long MIN = -10000000L;
	const long MAX = 10000000L;
	long start;
	long stop;
	double answers;

	printf("This program computes the sum of the squares of "
			"integers in a range.\nThe lower bound should not "
			"be less than -10000000 and\nThe upper bound "
			"should not be more than +10000000.\nEnter the "
			"limits (enter 0 for both limits to quit):\n"
			"lower limit: ");
	start = get_long();									//初次赋值
	printf("upper limit: ");
	stop = get_long();

	while (start != 0 || stop != 0)						//判断是否正常工作
	{
		if (bad_limits(start, stop, MIN, MAX))
			printf("Please try again.\n");
		else
		{
			answers = sum_squares(start, stop);			//计算平方和并打印
			printf("The sum of squares of the integers ");
			printf("from %ld to %ld is %g\n",
				start, stop, answers);
		}

		printf("Enter the limits (enter 0 for both "	//再次要求赋值上下限
			"limits to quit):\n");
		printf("lower limit: ");
		start = get_long();
		printf("upper_limit: ");
		stop = get_long();
	}
	printf("Done.\n");

	return 0;
}

long get_long(void)										//获取一个正常的整数
{
	long input;
	char ch;

	while (scanf("%ld", &input) != 1)					//若获取的是整数就跳出循环
	{
		while ((ch = getchar()) != '\n')				//吃掉输入缓冲区的字符（不是整数）。注意：最后一次也会把换行符给吃掉
			putchar(ch);
		printf(" is not an integer.\nPlease enter an ");
		printf("integer value,such as 25,-178, or 3: ");
	}

	return input;
}

double sum_squares(long a, long b)						//计算确定上下限的证书范围内的所有整数的平方和
{
	double total = 0;
	long i;

	for (i = a; i <= b; i++)
		total += (double)i * (double)i;

	return total;
}

bool bad_limits(long begin, long end, long low, long hign)	//确定输入的上下限是否正确
{
	bool not_good = false;

	if (begin > end)										//检查输入上限是否大于下限
	{
		printf("%ld isn't smaler than %ld .\n", begin, end);
		not_good = true;
	}
	if (begin < low || end < low)							//检查输入的上下限是否有小于程序设定的下线
	{
		printf("Value must be %ld or greater.\n", hign);
		not_good = true;
	}
	if (begin > hign || end > hign)							//检查输入的上下限是否有大于程序设定的上限
	{
		printf("Value must be %ld or less.\n", low);
		not_good = true;
	}

	return not_good;
}
