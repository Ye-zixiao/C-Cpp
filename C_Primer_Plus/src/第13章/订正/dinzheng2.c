#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZE 1024
void append(FILE* fs, FILE* ft);

int main(int argc, char* argv[])
{
	FILE* fs, * ft;
	char ch;
	int i;
	int files = 0;

	if (argc < 3)
	{
		fprintf(stderr, "Wrong Usage\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((ft = fopen(argv[1], "a+")) == NULL)
		{
			fprintf(stderr, "Can't create file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		if (setvbuf(ft, NULL, _IOFBF, BUFSIZE) != 0)
		{
			fprintf(stderr, "Can't create output buffer\n");
			exit(EXIT_FAILURE);
		}
		for (i = 2; i < argc; i++)
		{
			if (strcmp(argv[i], argv[1]) == 0)
			{
				fprintf(stderr, "Can't append itself\n");
				i++;
				continue;
			}
			else if((fs = fopen(argv[i], "r")) == NULL)
			{
				fprintf(stderr, "Can't open file %s\n", argv[i]);
				i++;
				continue;
			}
			else
			{
				if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
				{
					fprintf(stderr, "Can't create input buffer\n");
					continue;
				}
				append(fs, ft);
				if (ferror(fs) != 0)
					fprintf(stderr, "Error in reading file %s\n", argv[i]);
				if (ferror(ft) != 0)
					fprintf(stderr, "Error in writing file %s\n", argv[1]);
				files++;
				printf("file %s appended\n", argv[i]);
				fclose(fs);
			}
		}
		printf("%d files appended\n", files);
		printf("Target file shows at following:\n");
		rewind(ft);
		while ((ch = getc(ft)) != EOF)
			putc(ch, stdout);
		fclose(ft);
	}

	puts("\nDONE");
	return 0;
}


void append(FILE* fs, FILE* ft)
{
	size_t size;
	char temp[BUFSIZE];

	while ((size = fread(temp, sizeof(char), BUFSIZE, fs)) > 0)
		fwrite(temp, sizeof(char), size, ft);
}
