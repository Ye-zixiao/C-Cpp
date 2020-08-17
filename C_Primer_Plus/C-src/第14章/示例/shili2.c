#include<stdio.h>
#include<string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

char* s_gets(char* st, int n);

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index;

	printf("Please enter the book title.\n");
	printf("Press [enter] at the start of a line to stop.\n");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL							//读取书名
		&&library[count].title[0]!='\0')
	{
		printf("Now enter the author.\n");
		s_gets(library[count].author, MAXAUTL);														//读取书的作者
		printf("Now enter the value,\n");
		scanf("%f", &library[count++].value);														//读取书的价格，同时将计数值递增
		while (getchar() != '\n')																	//吃掉剩下的字符
			continue;
		if (count < MAXBKS)
			printf("Enter the next title.\n");
	}

	if (count > 0)
	{
		printf("Here is the list of your books:\n");
		for (index = 0; index < count; index++)
			printf("%s by %s: $%0.2f\n", library[index].title,
				library[index].author, library[index].value);
	}
	else
	{
		printf("No book? Too bad.\n");
	}

	return 0;
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);						//fgets()函数读到EOF时返回NULL空指针
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			* find = '\0';
		else
		{
			while (getchar() != '\n')
				continue;
		}
	}

	return ret_val;
}
