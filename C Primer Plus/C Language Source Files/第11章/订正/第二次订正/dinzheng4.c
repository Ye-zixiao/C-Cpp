/*-第11题*/
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define SIZE 81
#define LIM 10
char* s_gets(char* st, int n);
void print(char* st[], int string_ct);
void print_initial(char* st[], int string_ct);
void print_ascii(char* st[], int string_ct);
void print_length(char* st[], int string_ct);
int check_first_word(char* st);
void print_first_length(char* st[], int string_ct);
void menu(void);

int main(void)
{
	char input[LIM][SIZE];
	char* ptr[LIM];

	puts("Enter the strings for this program");
	int ct = 0;
	while (s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0'&&ct<SIZE)
	{
		ptr[ct] = input[ct];
		ct++;
	}

	char ch;
	menu();
	while ((ch = getchar()) != 'q')
	{
		if (ch == '\n')
			continue;
		switch (ch)
		{
			case 'a':
				print_initial(ptr, ct);				//注意传进去的是一位的指针数组,千万不要传递一个二级指针，这样类型不匹配
				break;
			case 'b':
				print_ascii(ptr, ct);
				break;
			case 'c':
				print_length(ptr, ct);
			case 'd':
				print_first_length(ptr, ct);
				break;
			default:
				puts("Enter the right form");
					break;
		}
		menu();
	}
	puts("Done");

	return 0;
}

void menu(void)
{
	puts("Enter the character to chooce");
	puts("a) print initially       b) print in ascii");
	puts("c) print in length       d) print in first word length");
	puts("q) quit");
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (*st != '\n' && *st != '\0')
			st++;
		if (*st == '\n')
			* st = '\0';
		else
			while (getchar() != '\n')
				continue;
		/* char *find;
			find=strchr(st,'\n');
			if(find)
				*find='\0';
			else
				while(getchar()!='\n')
					continue;
			*/
	}
	return ret_val;
}

void print(char* st[], int string_ct)
{
	int i;
	for (i = 0; i < string_ct; i++)
	{
		printf("%d: ", i);
		puts(st[i]);
	}
}

void print_initial(char* st[], int string_ct)
{
	static char * string[LIM];
	static bool flag = false;

	if (!flag)
	{
		int i;
		for (i = 0; i < string_ct; i++)
			string[i] = st[i];
		flag = true;
	}
	printf("print initially:\n");
	print(string, string_ct);
}

void print_ascii(char* st[], int string_ct)
{
	static char* string[LIM];
	static bool flag = false;

	if (!flag)
	{
		int i;
		for (i = 0; i < string_ct; i++)
			string[i] = st[i];

		char* temp;
		int top, seek;
		for(top=0;top<string_ct-1;top++)
			for(seek=top+1;seek<string_ct;seek++)
				if (strcmp(string[top], string[seek]) > 0)
				{
					temp = string[top];
					string[top] = string[seek];
					string[seek] = temp;
				}
		flag = true;
	}
	puts("pirnt in ascii");
	print(string, string_ct);
}

void print_length(char* st[], int string_ct)
{
	static char* string[LIM];
	static bool flag = false;

	if (!flag)
	{
		int i;
		for (i = 0; i < string_ct; i++)
			string[i] = st[i];

		char* temp;
		int top, seek;
		for (top = 0; top < string_ct - 1; top++)
			for (seek = top + 1; seek < string_ct; seek++)
				if (strlen(string[top])>strlen(string[seek]))
				{
					temp = string[top];
					string[top] = string[seek];
					string[seek] = temp;
				}
		flag = true;
	}
	puts("pirnt in length");
	print(string, string_ct);
}

int check_first_word(char* st)								//获得一串字符串的首单词的长度
{
	char ch;
	int first_space_ct = 0;
	int second_space_ct = 0;
	while (!isalpha(*st))									//如果不是字母，记录字母前非字母的长度和总的走过的长度
	{
		first_space_ct++;
		second_space_ct++;
		st++;
		continue;
	}
	while (isalpha(*st))									//继续增加中的走过的长度，直到读到非字母为止
	{
		second_space_ct++;
		st++;
	}
	return second_space_ct - first_space_ct;
}

void print_first_length(char* st[], int string_ct)			//核心思想：将input的字符串放在一个指针副本当中，对指针排序而不改变源字符串数组的指针
{
	static char* string[LIM];								//static的作用：是的string这个指针数组的存储周期变成静态存储期，当退出这个函数时仍
	static bool flag = false;								//然保存在内存当中。而标志位是用来检测下一次是否需要改动这个string指针数组

	if (!flag)												//第一次进入时才进入块中
	{
		int i;
		for (i = 0; i < string_ct; i++)						//先将传入的字符串指针给string这个指针数组
			string[i] = st[i];

		char* temp;
		int top, seek;
		for(top=0;top<string_ct-1;top++)
			for(seek=top+1;seek<string_ct;seek++)
				if (check_first_word(string[top]) > check_first_word(string[seek]))			//遍历判断首单词长度，重新对这个函数中的指针排序！
				{
					temp = string[top];
					string[top] = string[seek];
					string[seek] = temp;
				}
		flag = true;										//置位表示调用了第一次，以后不会进来修改了
	}
	puts("print in fisrt word length");
	print(string, string_ct);
}
