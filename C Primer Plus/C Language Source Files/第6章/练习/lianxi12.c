#include<stdio.h>//��Ƶ�̫���ڸ���
double sum1(int x);
int panduan(int y);
double sum2_1(int j);
double sum2_2(int k);

int main(void)
{
	int num;

	printf("Please enter the number for this program:\n");
	while (scanf("%d", &num), num > 0)
	{
		printf("The sum1=%.6f.\n", sum1(num));
		if (panduan(num) == -1)
		{
			printf("The sum2=%.6f.\n", sum2_1(num));
		}
		if (panduan(num) == 1)
		{
			printf("The sum2=%.6f.\n", sum2_2(num));
		}
		printf("Please keep entering .\n");
		printf("Enter the number<=0 to quit this program.\n");
	}
	printf("Done!\n");

	return 0;
}

double sum1(int x)//ȫ�Ǽӷ������
{
	double sum1 = 0;

	for (; x > 0; x--)
		sum1 += 1.0 /(double) x;

	return sum1;
}

int panduan(int y)
{
	int pan = 1;
	int j;

	for (j = 1; j <= y; j++)
		pan *= -1;

	return pan;
}

double sum2_1(int j)//���������
{
	int count_1, count_2;
	int n1, n2;
	double sum2_1_1=0, sum2_1_2=0;

	count_1 = (j - 1) / 2;//��������
	count_2 = (j - 1) / 2 + 1;//ż������

	for (n1 = 2; n1 <= count_1 * 2; n1 += 2)//�������е�ż����
		sum2_1_1 += 1.0 / n1;
	for (n2 = 1; n2 <= count_2 * 2 - 1; n2 += 2)//�������������ĺ�
		sum2_1_2 += 1.0 / n2;

	return sum2_1_2 - sum2_1_1;
}

double sum2_2(int k)//ż�������
{
	int count;
	int n1, n2;
	double sum2_2_1 = 0, sum2_2_2 = 0;
	count = k / 2;

	for (n1 = 2; n1 <= count * 2; n1 += 2)//�������е�ż����
		sum2_2_1 += 1.0 / n1;
	for (n2 = 1; n2 <= count * 2 - 1; n2 += 2)//�������������ĺ�
		sum2_2_2 += 1.0 / n2;

	return sum2_2_2 -sum2_2_1;
}
