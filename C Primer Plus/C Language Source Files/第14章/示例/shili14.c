#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
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
	int index, filecount;
	FILE* pbooks;
	int size = sizeof(struct book);

	if ((pbooks = fopen("book.dat", "a+b")) == NULL)							//�Զ��������ģʽ�򿪣��������ļ�
	{
		fprintf(stderr, "Can't open book.dat file.\n");
		exit(EXIT_FAILURE);
	}

	rewind(pbooks);
	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)		//���ļ��ж�ȡ�ṹ�������еĽṹ���鵱�У�����Ҳ����Ϊ��count������Ŀ��λ��
	{
		if (count == 0)
			puts("Current contents of book.dat:");
		printf("%s by %s: $%.2f\n", library[count].title,
			library[count].author, library[count].value);
		count++;
	}

	filecount=count;
	if (count == MAXBKS)														//�����ļ������ͽṹ��֮ǰ��Ҫ������ļ��еĽṹ�����Ƿ�����
	{
		fputs("The book.dat is full.", stderr);
		exit(EXIT_FAILURE);
	}

	puts("Please add new book titles.");
	puts("Press [enter] at the start of a line to stop.");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL		//���ļ�������µĽṹ��
		&& library[count].title[0] != '\0')
	{
		puts("Now enter the author.");
		s_gets(library[count].author, MAXAUTL);
		puts("Now enter the value.");
		scanf("%f", &library[count].value);
		while (getchar() != '\n')
			continue;
        fwrite(&library[count],size,1,pbooks);                                  //��ʵ��Ҳ������ÿһ�ζ�ȡ�����ݺ�ͽ�һ���ṹд�뵽�ļ�����
        count++;
		if (count < MAXBKS)
			puts("Enter the next title.");
	}

	if (count > 0)
	{
		puts("Here is the list of your books:");								//�ٴδ�ӡ�ļ��е����ݣ��ⲿ�ֵĴ�ӡ�����Ǵӳ����еĽṹ�����ж�ȡ�ģ��������ļ���
		for (index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", library[index].title,
				library[index].author, library[index].value);
		//fwrite(&library[filecount], size, count - filecount, pbooks);			//��fwrite�������ļ�����Ӻ����Լ���ӵ��鱾���ݣ��ܹ�����count-filecount������
	}                                                                           /*ʹ���ı��༭���򿪸��ļ�����Ȼԭ�ȵ��ı����ݿ��Բ鿴�����������ֲ��ֻ��������*/
	else
	{
		puts("No books? Too bad.\n");
	}
	puts("Bye.\n");
	fclose(pbooks);
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
