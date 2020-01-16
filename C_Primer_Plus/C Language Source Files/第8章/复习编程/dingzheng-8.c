/*这个程序吸收了CSDN上面的思想和书本上的思想*/
#include<stdio.h>
float get_number(void);											//获取一个数字
void menu(void);												    //打印菜单

int main(void)
{
	float num1, num2;
	char ch;

	menu();
	while ((ch = getchar()) != 'q')
	{
		while (getchar() != '\n')								//吃掉首字母后面的字符（包括换行符）
			continue;
		if (ch != 'a' && ch != 's' && ch != 'm' &&ch != 'd')        //排除其他字符带俩的干扰
		{
			printf("Please enter the right form(alphabet)\n");
			continue;
		}
		/*获取数字*/
		printf("Enter first number:");
		num1 = get_number();
		printf("Enter second number:");
		num2 = get_number();
        /*进行计算*/
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
				if (num2 == 0)							//当输入的第二个数值是0，要求重新输入
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

float get_number(void)								//获取一个浮点数
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
	getchar();										//吃掉scanf()函数按下时说带来的换行符

	return num;
}

void menu(void)
{
	printf("Enter the operation of your choice:\n");
	printf("a. add               s. subtract\n");
	printf("m. mutily            d. divide\n");
	printf("q. quit\n");
}
