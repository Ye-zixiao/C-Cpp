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
		switch (ch)											//判断输入的首字母是否符合要求
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
				while (getchar() != '\n')					//处理首字母后面的字符
					continue;
				continue;
		}
		while (getchar() != '\n')							//处置首字母后面的字符
			continue;

		/*获取数字*/
		printf("Enter first number:");
		num1=get_number();
		printf("Enter second number:");
		num2=get_number();

		if (add)									//加法
		{
			printf("%0.1f + %.1f = %.1f\n", num1, num2, num1 + num2);
			add = false;
		}
		if (subtract)								//减法
		{
			printf("%0.1f - %.1f = %.1f\n", num1, num2, num1 - num2);
			subtract = false;
		}
		if (multiply)								//乘法
		{
			printf("%0.1f * %.1f = %.1f\n", num1, num2, num1 * num2);
			multiply = false;
		}
		if (divide)									//除法
		{
			if (num2 == 0)							//当输入的第二个数值是0，要求重新输入
			{
				printf("Enter a number other than 0:");
				num2 = get_number();
			}
			printf("%0.1f / %.1f = %.1f\n", num1, num2, num1 / num2);
			divide = false;							//除法标志重新置位为false
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

float get_number(void)								//子函数：获取一个浮点数
{
	float num;
	char ch;

	while (scanf("%f", &num) != 1)					//若输入的不是数值：提醒并要求重复输入
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not a number\n");
		printf("Please enter a number ,such as 2.5,-1.78E8,or 3:");
	}

	return num;
}
