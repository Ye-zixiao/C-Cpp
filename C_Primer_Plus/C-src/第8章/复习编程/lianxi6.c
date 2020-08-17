#include<stdio.h>
char get_first(void);

int main(void)
{
	char ch;

	printf("Enter the words that you want\n");
	while ((ch = get_first()) != EOF)
	{
		putchar(ch);
		putchar('\n');
	}
	return 0;

}

char get_first(void)            //这个返回的字符只要不是空白字符即可
{
	char ch1;
	int get_it = 0;

	while (ch1 = getchar())
	{
		switch (ch1)
		{
			case '\n':
				continue;
			case ' ':
				continue;
			case '\t':
				continue;
			default:
				get_it=1;
		}
		while (getchar() != '\n')
			continue;
		if (get_it)
			break;
	}
	return ch1;
}
