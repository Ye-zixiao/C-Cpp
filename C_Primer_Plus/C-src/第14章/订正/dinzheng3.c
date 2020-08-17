/*                                                                  ����˼·�����ļ�-����ȡ���ݵ��ṹ����-���ж��Ƿ�����Ч����-���ǵĻ���ӡ����ʾ�Ƿ��޸�
                                                                        -��ɾ���Ļ����ǽ��ṹ�еı�־λ��Ϊɾ��״̬-���ر��ļ�-�����ڴ��еĽṹ����������ݣ��п���ʱ��
                                                                        -����ӡ������Ч����������ļ�����*/
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
	bool is_delete;								//��־λ�����߳�������Ƿ��Ǳ�ɾ����
}PACK;

char* s_gets(char* st, int n);
char getletter(char* st);						//��ȡһ����ĸ�����м�����ģ��
void modify(PACK* ele);							//�޸�һ���ṹ�����е�����
void menu(void);

int main(void)
{
	PACK arr[MAXBKS];
	FILE* fp;
	int count = 0;
	int filecount;
	int deletecount = 0;
	int size = sizeof(PACK);

	if ((fp = fopen("book.txt", "r")) != NULL)										//��һ���ļ�
	{
		rewind(fp);
		while (count < MAXBKS && fread(&arr[count], size, 1, fp) == 1)				//���ļ��е����ݸ��Ƶ��ṹ���鵱��
		{
			if (count == 0)
				puts("Current contents of books:");
			if (arr[count].is_delete == false)										//ֻ��û�б�ɾ���Ľṹ�ܹ�����ӡ
			{
				printf("%s by %s : $%.2f\n", arr[count].book_data.title, arr[count].book_data.author, arr[count].book_data.value);
				printf("Do you want to delete or modify this data?(y or n)\n");
				if (getletter("yn") == 'y')											//�������y�����޸�ģʽ
				{
					printf("Enter [d] to delete this book,and enter [m] to modify,and enter other character to cancel.\n");
					char ch = getletter("dmc");
					if (ch == 'd')
					{
						arr[count].is_delete = true;								//����־λ��Ϊtrue����ʾ�����ɾ��
						deletecount++;
					}
					else if (ch == 'm')
						modify(&arr[count]);										//�޸�����
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
	filecount = count - deletecount;												//�����޸ĺ���Ȼʣ�µ���Ŀ

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
		while (arr[i].is_delete == false)											//�ҵ����޸ĵĵط��������λ�ý���������ݣ���ס����Ķ�����ֻ�����ڴ��еĽṹ�������޸ġ����
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

	if ((fp = fopen("book.txt", "w")) == NULL)										//��дģʽ����Ϊдģʽ�ڴ򿪹����п��Բ���ʹ��fwrite���൱���ڲ�����ӣ�����һ���ϲ�Ҫ�����󣬶���Ҳ��Ҫ�����ģʽ��
	{																				//��Ϊ���ģʽ�������ǰ������������
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
				printf("%s by %s : $%.2f\n", arr[i].book_data.title, arr[i].book_data.title, arr[i].book_data.value);			//����ṹ�����е���Ч����
				fwrite(&arr[i], size, 1, fp);																					//��ѭ���в��Ͻ���Ч����д�뵽�ļ���
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
