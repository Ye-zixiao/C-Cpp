#include<string.h>
#include<stdio.h>
#define SIZE 15
char* mystrncpy(char* st1, const char* st2, int n);
void input(char* st, int n);

int main(void)
{
	//int n;
	char inputstr[20];
	char cpy[SIZE];
	char* ptr1 = inputstr;
	char* ptr2 = cpy;

	input(ptr1, 20);							//为其输入20个字符
	puts("the one I inputs:");
	puts(inputstr);
	ptr2 = mystrncpy(cpy, inputstr, SIZE - 1);
	ptr2[SIZE - 1] = '\0';						//给最后一个元素赋予空字符
	puts("the copy one:");
	puts(cpy);

	return 0;
}

void input(char* st, int n)
{
	int ct = 1;
	char ch;
	while ((ch = getchar()) != '\n' && ct <= n - 1)				//只赋值前面n-1个元素
	{
		*st = ch;
		st++;
		ct++;
	}
	*st = '\0';											//给最后一个元素赋予空指针
}

char* mystrncpy(char* st1, const char* st2, int n)//只能给他传SIZE-1
{
	char* ret_val;
	ret_val = st1;
	if ((int)strlen(st2) < n)       //st1容得下st2
	{
		while (*st2 != '\0')
		{
			*st1 = *st2;
			st2++;
			st1++;
		}
		*st1 = '\0';
	}
	else                    //容不下的情况
	{
		int ct;
		for (ct = 0; ct < n; ct++)
		{
			*st1 = *st2;
			st2++;
			st1++;
		}
	}

	return ret_val;
}
