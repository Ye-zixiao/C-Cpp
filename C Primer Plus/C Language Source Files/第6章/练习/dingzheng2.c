#include<stdio.h>
int main(void)
{
	int num, i;
	double sum1, sum2;

	printf("Enter a number for this program:\n");
	while (scanf("%d", &num), num > 0)          /*Ϊʲô����while�ж�����м������������ʽȴû�й�ϵ
                                                    ����Ϊwhileֻ�ж��ұߵı��ʽ�������������е㣬���Գ����Ǵ������ҽ��е�*/
	{
		for (i = 1, sum1 = 0; i <= num; i++)
			sum1 += 1.0 / i;
		printf("the sum1=%.3f\n", sum1);

		for (i = 1, sum2 = 0; i <= num; i++)
		{
			if (i % 2 == 1)                     //��ģ�ķ����ж���ż����ʲ���
				sum2 += 1.0 / i;
			else
				sum2 -= 1.0 / i;
		}
		printf("the sum2=%.3f\n", sum2);
	}

	return 0;
}
