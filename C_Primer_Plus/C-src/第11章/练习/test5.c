#include<stdio.h>
#include<ctype.h>
char* find_space(char* st);
char* s_gets(char* st, int n);

int main(void)
{
	char input[81];
	char* find=NULL;

	s_gets(input, 81);
	find=find_space(input);
	printf("address of first space is %p\n", find);

	return 0;
}

char* find_space(char* st)
{
	char* find=NULL;
	while (!isspace(*st)&&*st!='\0')
		st++;
	if (*st != '\0')//�����ָ��ǰ��û��ʲô���з���ֱ�ӷ��ؿ�ָ�룬����У��򷵻�find
		find = st;
	return find;
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
