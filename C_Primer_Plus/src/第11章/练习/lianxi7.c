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

	input(ptr1, 20);							//Ϊ������20���ַ�
	puts("the one I inputs:");
	puts(inputstr);
	ptr2 = mystrncpy(cpy, inputstr, SIZE - 1);
	ptr2[SIZE - 1] = '\0';						//�����һ��Ԫ�ظ�����ַ�
	puts("the copy one:");
	puts(cpy);

	return 0;
}

void input(char* st, int n)
{
	int ct = 1;
	char ch;
	while ((ch = getchar()) != '\n' && ct <= n - 1)				//ֻ��ֵǰ��n-1��Ԫ��
	{
		*st = ch;
		st++;
		ct++;
	}
	*st = '\0';											//�����һ��Ԫ�ظ����ָ��
}

char* mystrncpy(char* st1, const char* st2, int n)//ֻ�ܸ�����SIZE-1
{
	char* ret_val;
	ret_val = st1;
	if ((int)strlen(st2) < n)       //st1�ݵ���st2
	{
		while (*st2 != '\0')
		{
			*st1 = *st2;
			st2++;
			st1++;
		}
		*st1 = '\0';
	}
	else                    //�ݲ��µ����
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
