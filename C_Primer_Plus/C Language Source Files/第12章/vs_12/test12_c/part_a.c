#include<stdio.h>
extern void accumulate(int k);//�ⲿ������ʾ���������ڱ�ķ����ļ�����
static void report_ct(void);//��̬����ֻ���ڵ�ǰ�����ļ���Ѱ�Һ�������

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