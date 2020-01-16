//自己用switch做的
#include<stdio.h>
#define SPACE ' '
int main(void)
{
	int count = 0;
	char ch;

	while ((ch = getchar()) != EOF)
	{
		/*if (ch == '\n')			//吃掉第一个回车符
			continue;*/
		if (ch>=SPACE)
			printf("%7c", ch);
		else
		{
			switch (ch)
			{
				case '\0':
					printf("\\0");
					break;
				case '\a':
					printf("\\a");
					break;
				case '\t':
					printf("\\t");
					break;
				case '\n':
					printf("\\n");
						break;
				case '\r':
					printf("\\r");
					break;
				default:
					printf("^%c", ch+'A');
					break;
			}
		}
		printf(":%4d", ch);
		count++;
		if (count == 8)			//一行打印8对值
		{
			count = 0;
			printf("\n");
		}
		printf("    keep entering:");
	}
	printf("Done\n");

	return 0;
}
