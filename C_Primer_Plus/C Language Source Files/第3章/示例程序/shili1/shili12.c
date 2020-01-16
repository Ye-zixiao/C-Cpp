#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZE 4096
#define SLEN 20

char* s_gets(char* st, int n);
void append(FILE* fs, FILE* fa);

int main(int argc, char* argv[])//要求输入的只是目标文件
{
	FILE* fa, * fs;
	char ch;
	char source_file[SLEN];
	int files_ct = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Wrong usage.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((fa = fopen(argv[1], "a+")) == NULL)
		{
			fprintf(stderr, "Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
		{
			fputs("Can't create output buffer\n", stderr);
			exit(EXIT_FAILURE);
		}
		puts("Please enter the name of source file for this program:");
		while (s_gets(source_file, SLEN) != NULL && source_file[0] != '\0')//或者是利用argc的数值用for循环递减区去合并文件
		{
			if (strcmp(argv[1], source_file) == 0)
			{
				fputs("Can't append file to itself\n", stderr);
			}
			else if ((fs = fopen(source_file, "r")) == NULL)
			{
				fprintf(stderr,"Can't open file %s\n", source_file);
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
					fprintf(stderr, "Error in reading source file %s\n", source_file);
				if (ferror(fa) != 0)
					fprintf(stderr, "Error in writing target file %s\n", argv[1]);
				fclose(fs);
				files_ct++;
				fprintf(stdout, "file %s append.\n", source_file);
				puts("Please enter next name of source file for this program(empty line to quit): \n");
			}
		}
		printf("Done appending.%d files appended\n", files_ct);
		rewind(fa);
		printf("file %s display: \n", argv[1]);
		while ((ch = getc(fa)) != EOF)
			putc(ch, stdout);
		puts("Done.\n");
		fclose(fa);

		return 0;
	}
}

void append(FILE* fs, FILE* fa)
{
	char temp[BUFSIZE];
	size_t size;

	while ((size = fread(temp, sizeof(char), BUFSIZE, fs)) > 0)
		fwrite(temp, sizeof(char), size, fa);
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	int i=0;

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