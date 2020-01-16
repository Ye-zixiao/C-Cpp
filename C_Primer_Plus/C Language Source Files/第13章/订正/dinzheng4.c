#include<stdio.h>
#include<stdlib.h>
#define COLS 20
#define COLS 30
#define SLEN 20

const char trans[11] = " .':~*=&%#";
void makepic(const int (*num_arr)[COLS], char (*char_arr)[COLS], int n);

int main(void)
{
	FILE* fp;
	int i, j;
	char file_name[SLEN];
	int num_arr[COLS][COLS];
	char char_arr[COLS][COLS];

	printf("Enter the name of file you want to input: ");           //����Ҫ����ļ�
	scanf("%s", file_name);
	if ((fp = fopen(file_name, "r")) == NULL)
	{
		fprintf(stdout, "Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < COLS; i++)                                     //���ļ��е����ֶ�ȡ����ά���鵱��
		for (j = 0; j < COLS; j++)
			fscanf(fp, "%d", &num_arr[i][j]);
	if (ferror(fp) != 0)
	{
		fprintf(stderr, "Error in reading\n");
		exit(EXIT_FAILURE);
	}
	fclose(fp);

	makepic(num_arr, char_arr, COLS);
	for (i = 0; i < COLS; i++)                                  //��ӡ�����е��ַ�
	{
		for (j = 0; j < COLS; j++)
			putchar(char_arr[i][j]);
		putchar('\n');
	}

	return 0;
}

void makepic(const int(*num_arr)[COLS], char(*char_arr)[COLS], int n)           //����λ��ֵ���������ת���ɶ�ά�ַ�����
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < COLS; j++)
			char_arr[i][j] = trans[num_arr[i][j]];                     /*�������������֮�����ڴ���һ���ַ����������ڽ���
                                                                        Ӧ������ͨ�������ķ�ʽ����ֵת��Ϊ�ַ�*/
}
