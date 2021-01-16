#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SLEN 256

int main(int argc, char* argv[])
{
	FILE* fp;
	char temp[SLEN];

	if (argc != 3)
	{
		fprintf(stderr, "Wrong Usage\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((fp = fopen(argv[2], "r")) == NULL)                     //打开文件
		{
			fprintf(stderr, "Can't open file %s\n", argv[2]);
			exit(EXIT_FAILURE);
		}
		while ( fgets(temp,SLEN,fp) != NULL)                        //读取文件中的一行到temp数组当中
		{
			if (strstr(temp, argv[1]) != NULL)                      //比较字符串与需要比较的字符串是否相同
				fputs(temp,stdout);
		}
		fclose(fp);
	}

	puts("\nDONE");

	return 0;
}
