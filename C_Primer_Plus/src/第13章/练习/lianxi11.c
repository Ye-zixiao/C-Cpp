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
		if ((fp = fopen(argv[2], "r")) == NULL)                     //���ļ�
		{
			fprintf(stderr, "Can't open file %s\n", argv[2]);
			exit(EXIT_FAILURE);
		}
		while ( fgets(temp,SLEN,fp) != NULL)                        //��ȡ�ļ��е�һ�е�temp���鵱��
		{
			if (strstr(temp, argv[1]) != NULL)                      //�Ƚ��ַ�������Ҫ�Ƚϵ��ַ����Ƿ���ͬ
				fputs(temp,stdout);
		}
		fclose(fp);
	}

	puts("\nDONE");

	return 0;
}
