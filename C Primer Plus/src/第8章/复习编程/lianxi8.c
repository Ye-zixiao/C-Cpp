#include<stdio.h>
#include<stdbool.h>

float get_number(void);

int main(void)
{
	float num1, num2;
	char ch;
	bool add = false;
	bool multiply = false;
	bool subtract = false;
	bool divide = false;

	printf("Enter the operation of your choice:\n");
	printf("a. add               s. subtract\n");
	printf("m. mutily            d. divide\n");
	printf("q. quit\n");
	while ((ch = getchar()) != 'q')
	{
		switch (ch)											//�ж����������ĸ�Ƿ����Ҫ��
		{
			case '\n':
				continue;
			case 'a':
				add = true;
				break;
			case 's':
				subtract = true;
				break;
			case 'm':
				multiply = true;
				break;
			case 'd':
				divide = true;
				break;
			default:
				printf("Please enter the right form(alphabet)\n");
				while (getchar() != '\n')					//��������ĸ������ַ�
					continue;
				continue;
		}
		while (getchar() != '\n')							//��������ĸ������ַ�
			continue;

		/*��ȡ����*/
		printf("Enter first number:");
		num1=get_number();
		printf("Enter second number:");
		num2=get_number();

		if (add)									//�ӷ�
		{
			printf("%0.1f + %.1f = %.1f\n", num1, num2, num1 + num2);
			add = false;
		}
		if (subtract)								//����
		{
			printf("%0.1f - %.1f = %.1f\n", num1, num2, num1 - num2);
			subtract = false;
		}
		if (multiply)								//�˷�
		{
			printf("%0.1f * %.1f = %.1f\n", num1, num2, num1 * num2);
			multiply = false;
		}
		if (divide)									//����
		{
			if (num2 == 0)							//������ĵڶ�����ֵ��0��Ҫ����������
			{
				printf("Enter a number other than 0:");
				num2 = get_number();
			}
			printf("%0.1f / %.1f = %.1f\n", num1, num2, num1 / num2);
			divide = false;							//������־������λΪfalse
		}
		printf("Enter the operation of your choice:\n");
		printf("a. add               s. subtract\n");
		printf("m. mutily            d. divide\n");
		printf("q. quit\n");
		printf("\n");
	}
	printf("\n");

	return 0;

}

float get_number(void)								//�Ӻ�������ȡһ��������
{
	float num;
	char ch;

	while (scanf("%f", &num) != 1)					//������Ĳ�����ֵ�����Ѳ�Ҫ���ظ�����
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not a number\n");
		printf("Please enter a number ,such as 2.5,-1.78E8,or 3:");
	}

	return num;
}
