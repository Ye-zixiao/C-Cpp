/*-��11��*/
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
				print_initial(ptr, ct);				//ע�⴫��ȥ����һλ��ָ������,ǧ��Ҫ����һ������ָ�룬�������Ͳ�ƥ��
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

int check_first_word(char* st)								//���һ���ַ������׵��ʵĳ���
{
	char ch;
	int first_space_ct = 0;
	int second_space_ct = 0;
	while (!isalpha(*st))									//���������ĸ����¼��ĸǰ����ĸ�ĳ��Ⱥ��ܵ��߹��ĳ���
	{
		first_space_ct++;
		second_space_ct++;
		st++;
		continue;
	}
	while (isalpha(*st))									//���������е��߹��ĳ��ȣ�ֱ����������ĸΪֹ
	{
		second_space_ct++;
		st++;
	}
	return second_space_ct - first_space_ct;
}

void print_first_length(char* st[], int string_ct)			//����˼�룺��input���ַ�������һ��ָ�븱�����У���ָ����������ı�Դ�ַ��������ָ��
{
	static char* string[LIM];								//static�����ã��ǵ�string���ָ������Ĵ洢���ڱ�ɾ�̬�洢�ڣ����˳��������ʱ��
	static bool flag = false;								//Ȼ�������ڴ浱�С�����־λ�����������һ���Ƿ���Ҫ�Ķ����stringָ������

	if (!flag)												//��һ�ν���ʱ�Ž������
	{
		int i;
		for (i = 0; i < string_ct; i++)						//�Ƚ�������ַ���ָ���string���ָ������
			string[i] = st[i];

		char* temp;
		int top, seek;
		for(top=0;top<string_ct-1;top++)
			for(seek=top+1;seek<string_ct;seek++)
				if (check_first_word(string[top]) > check_first_word(string[seek]))			//�����ж��׵��ʳ��ȣ����¶���������е�ָ������
				{
					temp = string[top];
					string[top] = string[seek];
					string[seek] = temp;
				}
		flag = true;										//��λ��ʾ�����˵�һ�Σ��Ժ󲻻�����޸���
	}
	puts("print in fisrt word length");
	print(string, string_ct);
}
