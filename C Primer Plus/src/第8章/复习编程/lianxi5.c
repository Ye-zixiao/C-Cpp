#include <stdio.h>
#include<stdbool.h>

int main(void)
{
	int big = 100;				//ע�⣺����ʱ��Ҫʹ�õ������������
	int small = 0;
	int num = 50;
	char ch;
	bool get_it = false;

	printf("I guess the number you want is %d\n", num);
	printf("Enter the s (means it is small) or b(means it is big) or y(means it successes)\n");

	while ((ch = getchar()) != EOF)
	{
		switch (ch)
		{
			case '\n':
				continue;
			case 'y':
				printf("I knew that I can do it.\n");
				get_it = true;
				break;
			case 's':							//С��
				small = num;					//�滻��Сֵ
				num = (num + big) / 2;
				printf("I guess the number you want is %d\n", num);
				break;
			case 'b':							//����
				big = num;						//�滻�ϴ�ֵ
				num = (small + num) / 2;
				printf("I guess the number you want is %d\n", num);
				break;
			default:
				printf("Please enter the right form\n");
				break;
		}
		if (get_it)
			break;
	}
	printf("Done\n");

	return 0;
}
