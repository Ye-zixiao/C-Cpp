#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SLEN 20

int main(void)
{
	FILE* fs, *f_temp;
	char ch;
	char file_name[SLEN];

	printf("Enter the name of file that you want: ");
	scanf("%s", file_name);
	if ((fs = fopen(file_name, "r")) == NULL)
	{
		fprintf(stderr, "Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	if ((f_temp = fopen("temp.txt", "w")) == NULL)
	{
		fprintf(stderr, "Error in creating temp_file\n");
		exit(EXIT_FAILURE);
	}
	while ((ch = fgetc(fs)) != EOF)
	{
		if (isalpha(ch))
			putc(tolower(ch), f_temp);
		else
			putc(ch, f_temp);
	}
	fclose(fs);
	fclose(f_temp);

	if ((fs = fopen(file_name, "w")) == NULL)
	{
		fprintf(stderr, "Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	if ((f_temp = fopen("temp.txt", "r")) == NULL)
	{
		fprintf(stderr, "Can't open temp_file\n");
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(f_temp)) != EOF)
	{
		putc(ch, fs);
	}

	fclose(fs);
	fclose(f_temp);
	remove(f_temp);
	puts("\nDONE");
	return 0;
}
