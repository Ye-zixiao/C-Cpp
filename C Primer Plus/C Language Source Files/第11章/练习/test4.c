#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LIM 30
char* s_gets(char* st, int n);

int main(void)
{
	char number[LIM];
	char* end = NULL;
	long value;

	puts("Enter a number (empty line to quit):");
	while (s_gets(number, LIM) && number[0] != '\0')
	{
		printf("Before the changing the end is %p\n", end);
		value = strtol(number, &end, 10);                           /*��strtol��������һ��ָ��ָ���ָ��
															��ָ��ĵ�ַ����Ŀ����Ϊ�˸ı�end��ֵ��ʹ֮�ܹ�����ָ��һ���µı���*/
		printf("After the changing the end is %p\n", end);
		printf("&number[2] is %p\n", &number[2]);
		printf("base 10 input,base 10 output:%ld,stoped at %s (%d)\n", value, end, *end);

		value = strtol(number, &end, 16);
		printf("base 16 input,base 10 output:%ld,stoped at %s (%d)\n", value, end, *end);
		puts("Next number:");
	}
	puts("Bye!\n");

	return 0;
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		char* find;
		find = strchr(st, '\n');
		if (find)                   //�ֽ�ȥ�жϿ�ָ��Ҳ��ȫû����
			* find = '\0';
		else
		{
		    while (getchar() != '\n')
				continue;
		}
	}
	return ret_val;
}
