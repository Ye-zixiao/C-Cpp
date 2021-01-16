#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SLEN 20

int main(void)
{
	FILE* fp;
	int i;
	int serial;
	char ch;
	char file_name[SLEN];

	printf("Please enter the name of file that you want: ");
	fscanf(stdin, "%s", file_name);
	if ((fp = fopen(file_name, "r")) == NULL)                               //���ļ�
	{
		fprintf(stderr, "Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	printf("Enter the serial number of line that you want: ");
	while ((scanf("%d", &serial) == 1) && serial > 0)                       //���벢�жϵڼ��п�ʼ��ȡ
	{
		for (i = 1; i < serial; i++)                                        //���ļ�λ��ָʾ���Ƶ�������
			while (getc(fp) != '\n')
				continue;
		printf("Enter the serial number of row that you want: ");
		scanf("%d", &serial);
		for (i = 1; i < serial; i++)                                        //���ļ�λ��ָʾ�������ƶ���ָ��λ��
			getc(fp);

		printf("Result shows at the follwing:\n");
		while (((ch = getc(fp)) != '\n')&&(ch!=EOF))                        //��ӡ�����з�ǰ���ַ�
			putc(ch, stdout);
		rewind(fp);
		printf("\nEnter the serial number of line again for this program(-1 to quit): ");
	}
	fclose(fp);

	puts("\nDONE");
	return 0;
}
