/*                                                                  解题思路：打开文件-》读取数据到结构数组-》判断是否是有效数据-》是的话打印并提示是否修改
                                                                        -》删除的话就是将结构中的标志位置为删除状态-》关闭文件-》对内存中的结构数组添加数据（有空余时）
                                                                        -》打印并将有效数据输出到文件当中*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

typedef struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

typedef struct pack {
	struct book book_data;
	bool is_delete;								//标志位：告诉程序这个是否是被删除了
}PACK;

char* s_gets(char* st, int n);
char getletter(char* st);						//获取一个字母，其中加入检错模块
void modify(PACK* ele);							//修改一个结构变量中的数据
void menu(void);

int main(void)
{
	PACK arr[MAXBKS];
	FILE* fp;
	int count = 0;
	int filecount;
	int deletecount = 0;
	int size = sizeof(PACK);

	if ((fp = fopen("book.txt", "r")) != NULL)										//打开一个文件
	{
		rewind(fp);
		while (count < MAXBKS && fread(&arr[count], size, 1, fp) == 1)				//将文件中的数据复制到结构数组当中
		{
			if (count == 0)
				puts("Current contents of books:");
			if (arr[count].is_delete == false)										//只有没有被删除的结构能够被打印
			{
				printf("%s by %s : $%.2f\n", arr[count].book_data.title, arr[count].book_data.author, arr[count].book_data.value);
				printf("Do you want to delete or modify this data?(y or n)\n");
				if (getletter("yn") == 'y')											//如果输入y进入修改模式
				{
					printf("Enter [d] to delete this book,and enter [m] to modify,and enter other character to cancel.\n");
					char ch = getletter("dmc");
					if (ch == 'd')
					{
						arr[count].is_delete = true;								//将标志位置为true，表示这个被删除
						deletecount++;
					}
					else if (ch == 'm')
						modify(&arr[count]);										//修改数据
					else
					{
						//nothing to do
					}
				}
			}
			count++;
		}
	}
	else
	{
		fputs("Error in opening file book.txt.\n", stderr);
		exit(EXIT_FAILURE);
	}
	fclose(fp);
	filecount = count - deletecount;												//计算修改后仍然剩下的书目

	if (filecount == MAXBKS)
	{
		fprintf(stderr, "The library is full.\n");
		exit(EXIT_FAILURE);
	}

	printf("Please add new book title.\n");
	puts("Press [enter] to quit.");
	while (filecount < MAXBKS)
	{
		int i = 0;
		while (arr[i].is_delete == false)											//找到被修改的地方，对这个位置进行添加数据，记住这个改动现在只是在内存中的结构数组中修改、添加
			i++;
		if (s_gets(arr[i].book_data.title, MAXTITL) == NULL || arr[i].book_data.title[0] == '\0')
			break;
		printf("Now enter the author: ");
		s_gets(arr[i].book_data.author, MAXAUTL);
		printf("Now enter the value of this book: ");
		scanf("%f", &arr[i].book_data.value);
		while (getchar() != '\n')
			continue;
		arr[i].is_delete = false;
		filecount++;
		if (filecount < MAXBKS)
			printf("Enter the next title: ");
	}

	if ((fp = fopen("book.txt", "w")) == NULL)										//以写模式，因为写模式在打开过程中可以不断使用fwrite，相当于在不断添加，在这一点上不要理解错误，而且也不要用添加模式打开
	{																				//因为添加模式不会把以前错误的数据清空
		fprintf(stderr, "Can't open file book.txt.\n");
		exit(EXIT_FAILURE);
	}
	if (filecount > 0)
	{
		puts("Here is the list of your book: ");
		int i;
		for (i = 0; i < MAXBKS; i++)
		{
			if (arr[i].is_delete == false)
			{
				printf("%s by %s : $%.2f\n", arr[i].book_data.title, arr[i].book_data.title, arr[i].book_data.value);			//输出结构数组中的有效数据
				fwrite(&arr[i], size, 1, fp);																					//在循环中不断将有效数据写入到文件中
			}
		}
	}
	else
		puts("Too bad,no books.");
	fclose(fp);

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

char getletter(char* st)
{
	char ch;
	ch = getchar();
	while (1)
	{
		if (strchr(st, ch) != NULL)
			break;
		else
		{
			printf("Enter the character in string %s.\n", st);
			while (getchar() != '\n')
				continue;
			ch = getchar();
		}
	}
	while (getchar() != '\n')
		continue;
	return ch;
}
void menu(void)
{
	puts("Enter the number to chooice the following function.");
	puts("1) modify book title       2) modify book author");
	puts("3) modify book value       4) quit");
}

void modify(PACK* ele)
{
	int chooice;
	bool quit_flag = false;
	menu();
	scanf("%d", &chooice);
	while (getchar() != '\n')
		continue;
	while (1)
	{
		switch (chooice)
		{
		case 1:
			printf("Enter the new title: ");
			s_gets(ele->book_data.title, MAXTITL);
			break;
		case 2:
			printf("Enter the new author name: ");
			s_gets(ele->book_data.author, MAXAUTL);
			break;
		case 3:
			printf("Enter the new value: ");
			float temp;
			while ((scanf("%f", &temp) != 1) || temp < 0)
			{
				printf("Enter numeric value: ");
				while (getchar() != '\n')
					continue;
			}
			ele->book_data.value = temp;
			break;
		case 4:
			quit_flag = true;
			break;
		}
		if (quit_flag)
			break;
		menu();
		scanf("%d", &chooice);
	}
	while (getchar() != '\n')
		continue;
}
