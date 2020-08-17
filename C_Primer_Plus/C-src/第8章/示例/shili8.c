/* 对书中P236、237、238、239的程序的修改1：基本解决了scanf函数输入数字带来的换行符问题，
缺点：count函数不能处理非数字字符*/
#include<stdio.h>
char get_choice(void);
void count(void);
char get_first(void);

int main(void)
{
	char choice;

	printf("Please choice: \n");
	while ((choice = get_choice()) != 'q')
	{
		switch (choice)
		{
			case 'a':
				printf("Buy low,sell high.\n");
				break;
			case 'b':
				putchar('\a');
				break;
			case 'c':
				count();
				break;
			case '\n':
				printf("Program error.\n");
				break;
		}
		printf("Rechoice:\n");
	}
	printf("Done.\n");

	return 0;
}

char get_choice(void)
{
	char ch;

	printf("Enter the letter of your choice:\n");
	printf("a) advice           b) bell\n");
	printf("c) count            q) quit\n");
	ch = get_first();
	while ((ch<'a' || ch>'c') && ch != 'q')
	{
		printf("Please respond with a,b,c, or q.\n");
		ch = get_first();
	}

	return ch;
}

void count(void)
{
	int n, i;
	printf("Count how far?Enter an integer:\n");
	scanf("%d", &n);                                //这里有个缺点：不能对非数字的字符进行处理
	for (i = 1; i <= n; i++)
		printf("%d\n", i);
}

char get_first(void)
{
	char ch;

	while ((ch = getchar()) == '\n')			//判断第一个输入是否为换行符，若是再次读取，直到读取的不是换行符
		continue;

	while (getchar() != '\n')
		continue;

	return ch;
}
/*详见书中的P236和P237。
虽然书中说到（P237）在不做修改的情况下，运行程序：选择c然后调用scanf()函数后输入数字+ENTER后引入了换行符'\n'
，再次回车后get_first()的ch = getchar()读取这个保留在输入缓冲区中的换行符，但是在接下来的运行当中由于'\n'的
ASCII码是10小于'a'满足while ((ch<'a' || ch>'c') && ch != 'q'&&ch!='\n')的测试表达式，就进入了这个循环体当中
，并输出Please respond with a,b,c, or q. 然后又等待输入。这样我们就见不到Program error.这句话。
	如果要见到这句话就需要在while ((ch<'a' || ch>'c') && ch != 'q'&&ch!='\n')中的测试表达式当中加入&&ch!='\n'
这样我们就能见到这个错误了，这样也很好地展示了scanf函数与getchar函数一起使用（书中表述为混合字符和数字输入问题
）时的区别*/
