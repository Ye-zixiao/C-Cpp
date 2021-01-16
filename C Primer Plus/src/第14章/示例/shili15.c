#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define LEN 30

char* s_gets(char* st, int n);

enum spetrum {red,orange,yellow,green,blue,violet};					//声明了一个枚举类型
const char* colors[] = { "red","orange","yellow",					//定义了一个指针数组，分别指向各自的字符常量
						"green","blue","violet" };

int main(void)
{
	char choice[LEN];
	enum spetrum color;												//定义了一个枚举变量
	bool color_is_found = false;									//标志

	puts("Enter a color (empty line to quit):");
	while (s_gets(choice, LEN) != NULL && choice[0] != '\0')
	{
		for (color = red; color <= violet; color++)					//将输入的字符串与程序中的字符串常量进行比较，找出那个字符串。如果找到就将标志位置为true
		{
			if (strcmp(choice, colors[color]) == 0)
			{
				color_is_found = true;
				break;
			}
		}

		if (color_is_found)											//若找到，进入switch语句中打印输出
			switch (color)
			{
			case red:
				puts("Rose is red.");
				break;
			case orange:
				puts("Poppies are orange.");
				break;
			case yellow:
				puts("Sunflowers are yellow.");
				break;
			case green:
				puts("Grass is green,");
				break;
			case blue:
				puts("Bluebells are blue.");
				break;
			case violet:
				puts("Violets are violet.");
				break;
			}
		else
			printf("I don't know  about the color %s\n", choice);
		color_is_found = false;									//重新将标志位置为false
		puts("Next color,please (empty line to quit):");
	}

	puts("Goodbye.");

	return 0;
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			* find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
