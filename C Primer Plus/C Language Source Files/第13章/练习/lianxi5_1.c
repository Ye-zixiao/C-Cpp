#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZE 1024
void append(FILE* fs, FILE* fa);
char* s_gets(char* st, int n);

int main(int argc, char* argv[])//目标文件   源文件。。
{
	FILE* fa, * fs;
	char ch;
	int files_ct = 0;
	int i;

	printf("argc=%d\n", argc);
	if (argc <= 1)
	{
		fprintf(stderr, "Wrong Usage.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((fa = fopen(argv[1], "a+")) == NULL)
		{
			fprintf(stderr, "Can't open target file\n");
			exit(EXIT_FAILURE);
		}
		if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
		{
			fprintf(stderr, "Can't create output buffer\n");
			exit(EXIT_FAILURE);
		}
		for (i = 2; i < argc;i++ )
		{
			if (strcmp(argv[1], argv[i]) == 0)
			{
				fprintf(stderr, "Warning: can't append to itself\n");
				i++;
				continue;
			}
			else if ((fs = fopen(argv[i], "r")) == NULL)
			{
				fprintf(stderr, "Can't open file %s\n", argv[i]);
			}
			else
			{
				if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
				{
					fprintf(stderr, "Can't create input buffer\n");
					continue;
				}
				append(fs, fa);
				if (ferror(fs) != 0)
					fprintf(stderr, "Error in reading file %s\n", argv[i]);
				if (ferror(fa) != 0)
					fprintf(stderr, "Error in writing file %s\n", argv[1]);
				fclose(fs);
				files_ct++;
				printf("File %s appended\n", argv[i]);
			}
		}
		printf("Done appending.\n%d file(s) appended.\n", files_ct);
		printf("File of target displayed at the fllowing:\n");
		rewind(fa);
		while ((ch = getc(fa)) != EOF)
			putchar(ch);
		fclose(fa);

		puts("\nDone");
		return 0;
	}
}

void append(FILE* fs, FILE* fa)
{
	static char temp[BUFSIZE];
	size_t size;
	//int size;

	while ((size = fread(temp, sizeof(char), BUFSIZE, fs)) > 0)
		fwrite(temp, sizeof(char), size, fa);
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
