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
			for (i = 2; i <= num; i++)			//�����������ǲ����1�����жϵģ���Ϊ1��forѭ���嶼����ȥ������Ҫ��1�����ж�
			{
				for (j = 2, isprime = 1; j * j <= i; j++)
				{
					if (i % j == 0)
					{
						isprime = 0;			//˵������������
						break;					//����ѭ��
					}
				}
				if (isprime)					//��ÿһ��������ӡ
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
