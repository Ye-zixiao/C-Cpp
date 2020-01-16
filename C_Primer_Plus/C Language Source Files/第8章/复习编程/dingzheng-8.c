/*�������������CSDN�����˼����鱾�ϵ�˼��*/
#include<stdio.h>
float get_number(void);											//��ȡһ������
void menu(void);												    //��ӡ�˵�

int main(void)
{
	float num1, num2;
	char ch;

	menu();
	while ((ch = getchar()) != 'q')
	{
		while (getchar() != '\n')								//�Ե�����ĸ������ַ����������з���
			continue;
		if (ch != 'a' && ch != 's' && ch != 'm' &&ch != 'd')        //�ų������ַ������ĸ���
		{
			printf("Please enter the right form(alphabet)\n");
			continue;
		}
		/*��ȡ����*/
		printf("Enter first number:");
		num1 = get_number();
		printf("Enter second number:");
		num2 = get_number();
        /*���м���*/
		switch (ch)
		{
			case 'a':
				printf("%0.1f + %.1f = %.1f\n", num1, num2, num1 + num2);
				break;
			case 's':
				printf("%0.1f - %.1f = %.1f\n", num1, num2, num1 - num2);
				break;
			case 'm':
				printf("%0.1f * %.1f = %.1f\n", num1, num2, num1 * num2);
				break;
			case 'd':
				if (num2 == 0)							//������ĵڶ�����ֵ��0��Ҫ����������
				{
					printf("Enter a number other than 0:");
					num2 = get_number();
				}
				printf("%0.1f / %.1f = %.1f\n", num1, num2, num1 / num2);
			default:
				break;
		}
		menu();
		printf("\n");
	}
	printf("Done\n");

	return 0;

}

float get_number(void)								//��ȡһ��������
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
	getchar();										//�Ե�scanf()��������ʱ˵�����Ļ��з�

	return num;
}

void menu(void)
{
	printf("Enter the operation of your choice:\n");
	printf("a. add               s. subtract\n");
	printf("m. mutily            d. divide\n");
	printf("q. quit\n");
}
