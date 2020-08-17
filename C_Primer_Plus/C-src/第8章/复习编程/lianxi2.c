#include<stdio.h>
#define SPACE ' '
int main(void)
{
	int count = 0;
	char ch;

	while ((ch = getchar()) != EOF)
	{
		if (ch == '\n')			//吃掉第一个回车符
			continue;
		if (ch>=SPACE)
			printf("%7c", ch);
		else
		{
			switch (ch)
			{
				case '\0':
					printf("%7s", "\0");
					break;
				case '\a':
					printf("%7s", "\a");
					break;
				case '\t':
					printf("%s", "\t");
					break;
				/*case '\n':
					printf("%7s", "\n");
					break;*/
				case '\r':
					printf("%7s", "\r");
					break;
				default:
					printf("Ctrl+%c", 'A' + (int)ch);
					break;
			}
		}
		printf("%4d", (int)ch);
		count++;
		if (count == 8)			//一行打印8对值
		{
			count = 0;
			printf("\n");
		}
	}
	printf("Done\n");

	return 0;
}
