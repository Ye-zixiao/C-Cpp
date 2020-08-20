#include<stdio.h>
void menu1(void);
int get_number(int, int);

int main(void)
{
	int num;

	menu1();
	num = get_number(0, 4);
	printf("num=%d\n", num);

	return 0;
}

void menu1(void)										//给出菜单
{
	printf("Please choose one of the following:\n");
	printf("1) copy files            2) move files\n");
	printf("3) remove files          4) quit\n");
	printf("Enter the number of your choice:");
}

int get_number(int l_limit, int h_limit)				//获取一个符合范围的数字
{
	int temp;
	char ch;
	int rv=0;

	while ((rv=scanf("%d", &temp))== 1 && (temp <l_limit || temp>h_limit))//超出了范围
	{
		printf("%d is not right form to this program\n", temp);
		while (getchar() != '\n')				//吃掉后面的字符
			continue;
		menu1();
		printf("\n");
		rv = 0;//重置输入数字标识符
	}
	if (rv!=1)//如果输入的是非整型字符,返回4，同时吃掉后面的字符
	{
		while (getchar() != '\n')
			continue;
		return 4;
	}

	return temp;
}
