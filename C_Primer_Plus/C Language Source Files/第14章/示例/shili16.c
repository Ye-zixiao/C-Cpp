#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define LEN 81
char* s_gets(char* st, int n);
char showmenu(void);
void eatline(void);													//吃掉缓冲区中的数据
void show(void (*fp)(char*), char* str);							//一个接受函数指针和字符串指针的打印函数
void ToUpper(char*);
void ToLower(char*);
void Transpose(char*);												//大小写置换
void Dummy(char*);													//空操作

int main(void)
{
	char line[LEN];
	char copy[LEN];
	char choice;
	void (*pfun)(char*);

	puts("Enter a string (empty line to quit):");
	while (s_gets(line, LEN) != NULL && line[0] != '\0')
	{
		while ((choice = showmenu()) != 'n')
		{
			switch (choice)
			{
			case 'u':pfun = ToUpper; break;
			case 'l':pfun = ToLower; break;
			case 't':pfun = Transpose; break;
			case 'o':pfun = Dummy; break;
			}
			strcpy(copy, line);										//创建一个字符串副本
			show(pfun, copy);										//按照自己的输入将字符串转换为相应的字符串，然后将之输出
		}
		puts("Enter a string (empty line to quit):");
	}
	puts("Bye!");

	return 0;
}

char showmenu(void)
{
	char ans;
	puts("Enter menu choice:");
	puts("u) uppercase        l) lowercase");
	puts("t) transposed case  o) original case");
	puts("n) next string");
	ans = getchar();												//要求输入一个字符
	ans = tolower(ans);
	eatline();
	while (strchr("ulton", ans) == NULL)
	{
		puts("Please enter a u,l,t,o,or n:");
		ans = tolower(getchar());
		eatline();
	}
	return ans;
}

void eatline(void)
{
	while (getchar() != '\n')
		continue;
}

void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char* str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}

void Transpose(char* str)
{
	while (*str)
	{
		if (islower(*str))
			* str = toupper(*str);
		else if (isupper(*str))
			* str = tolower(*str);
		str++;
	}
}

void Dummy(char* str)
{
	//空操作
}

void show(void (*fp)(char*), char* str)
{
	(*fp)(str);
	puts(str);
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
