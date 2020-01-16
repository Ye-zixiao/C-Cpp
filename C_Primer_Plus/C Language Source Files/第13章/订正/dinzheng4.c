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

	printf("Enter the name of file you want to input: ");           //按照要求打开文件
	scanf("%s", file_name);
	if ((fp = fopen(file_name, "r")) == NULL)
	{
		fprintf(stdout, "Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < COLS; i++)                                     //将文件中的数字读取到二维数组当中
		for (j = 0; j < COLS; j++)
			fscanf(fp, "%d", &num_arr[i][j]);
	if (ferror(fp) != 0)
	{
		fprintf(stderr, "Error in reading\n");
		exit(EXIT_FAILURE);
	}
	fclose(fp);

	makepic(num_arr, char_arr, COLS);
	for (i = 0; i < COLS; i++)                                  //打印数组中的字符
	{
		for (j = 0; j < COLS; j++)
			putchar(char_arr[i][j]);
		putchar('\n');
	}

	return 0;
}

void makepic(const int(*num_arr)[COLS], char(*char_arr)[COLS], int n)           //将二位数值数组的数据转换成二维字符数组
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < COLS; j++)
			char_arr[i][j] = trans[num_arr[i][j]];                     /*这个方法的巧妙之处在于创建一个字符串数组用于将相
                                                                        应的数字通过索引的方式将数值转化为字符*/
}
