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
	if ((fp = fopen(file_name, "r")) == NULL)                               //打开文件
	{
		fprintf(stderr, "Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	printf("Enter the serial number of line that you want: ");
	while ((scanf("%d", &serial) == 1) && serial > 0)                       //输入并判断第几行开始读取
	{
		for (i = 1; i < serial; i++)                                        //将文件位置指示器移到输入行
			while (getc(fp) != '\n')
				continue;
		printf("Enter the serial number of row that you want: ");
		scanf("%d", &serial);
		for (i = 1; i < serial; i++)                                        //将文件位置指示器继续移动到指定位置
			getc(fp);

		printf("Result shows at the follwing:\n");
		while (((ch = getc(fp)) != '\n')&&(ch!=EOF))                        //打印出换行符前的字符
			putc(ch, stdout);
		rewind(fp);
		printf("\nEnter the serial number of line again for this program(-1 to quit): ");
	}
	fclose(fp);

	puts("\nDONE");
	return 0;
}
