//CSDN上的答案，不过这题本身也不太好处理
#include<stdio.h>

int main(void)
{
	char ch = 0;
	int n_char = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\n')
			continue;
		n_char++;
		if (ch < ' ')               //控制字符
		{
			if ('\t' == ch)
			{
				putchar('\\');
				putchar('t');
				printf(":%d ", ch);
			}
			else if ('\n' == ch)
			{
				putchar('\\');
				putchar('n');
				printf(":%d ", ch);
			}
			else
			{
				putchar('^');
				putchar(ch + 64);
				printf(":%d ", ch);
			}
		}
		else                        //可打印字符
		{
			putchar(ch);
			printf(":%d ", ch);
		}
		if (n_char % 10 == 0)      //控制一行字符对数
		{
			printf("\n");
		}

	}
	return 0;
}
