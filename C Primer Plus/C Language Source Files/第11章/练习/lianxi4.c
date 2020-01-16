#include<stdio.h>
#include<ctype.h>
#define SIZE 10
void storeword(char* str, int max);

int main(void)
{
	char input[SIZE];
	storeword(input, SIZE - 1);
	puts(input);

	return 0;
}

void storeword(char* str, int max)                   //max是读取单词的最大上限
{
	char ch;
	int ct = 0;

	while (isspace(ch = getchar()))
		continue;
	do
	{
		*str = ch;                                    //先将上一个循环的字符读取到数组当中
		str++;
		ct++;
	} while (!isspace(ch = getchar()) && ct <= max-1);       /*如果不是空白字符我就继续从输入缓冲区中读取字符，
														缺点：getchar会吃掉一个换行符（出现在只有一个单词的情况）*/
	*str = '\0';                                    //给数组最后的位置放一个空字符
	if(ch!='\n')                                            //这样就防止吃掉回车符后还要求输入一个字符
		while (getchar() != '\n')
			continue;
}
