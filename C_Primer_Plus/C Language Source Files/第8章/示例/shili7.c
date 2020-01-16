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
	start = get_long();									//���θ�ֵ
	printf("upper limit: ");
	stop = get_long();

	while (start != 0 || stop != 0)						//�ж��Ƿ���������
	{
		if (bad_limits(start, stop, MIN, MAX))
			printf("Please try again.\n");
		else
		{
			answers = sum_squares(start, stop);			//����ƽ���Ͳ���ӡ
			printf("The sum of squares of the integers ");
			printf("from %ld to %ld is %g\n",
				start, stop, answers);
		}

		printf("Enter the limits (enter 0 for both "	//�ٴ�Ҫ��ֵ������
			"limits to quit):\n");
		printf("lower limit: ");
		start = get_long();
		printf("upper_limit: ");
		stop = get_long();
	}
	printf("Done.\n");

	return 0;
}

long get_long(void)										//��ȡһ������������
{
	long input;
	char ch;

	while (scanf("%ld", &input) != 1)					//����ȡ��������������ѭ��
	{
		while ((ch = getchar()) != '\n')				//�Ե����뻺�������ַ���������������ע�⣺���һ��Ҳ��ѻ��з����Ե�
			putchar(ch);
		printf(" is not an integer.\nPlease enter an ");
		printf("integer value,such as 25,-178, or 3: ");
	}

	return input;
}

double sum_squares(long a, long b)						//����ȷ�������޵�֤�鷶Χ�ڵ�����������ƽ����
{
	double total = 0;
	long i;

	for (i = a; i <= b; i++)
		total += (double)i * (double)i;

	return total;
}

bool bad_limits(long begin, long end, long low, long hign)	//ȷ��������������Ƿ���ȷ
{
	bool not_good = false;

	if (begin > end)										//������������Ƿ��������
	{
		printf("%ld isn't smaler than %ld .\n", begin, end);
		not_good = true;
	}
	if (begin < low || end < low)							//���������������Ƿ���С�ڳ����趨������
	{
		printf("Value must be %ld or greater.\n", hign);
		not_good = true;
	}
	if (begin > hign || end > hign)							//���������������Ƿ��д��ڳ����趨������
	{
		printf("Value must be %ld or less.\n", low);
		not_good = true;
	}

	return not_good;
}
