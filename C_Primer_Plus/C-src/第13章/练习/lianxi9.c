#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SLEN 20

int main(void)
{
	FILE* fp;
	char file_name[SLEN];
	int ct=1;
	char ch;
	char word[SLEN];

	puts("Enter the name of file:");
	scanf("%s", file_name);
	if ((fp = fopen(file_name, "a+")) == NULL)
	{
		fprintf(stderr, "Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
		if (ch == '\n')
			ct++;
	rewind(fp);
	/*书本答案的做法

	rewind(fp);
	int wordct=0;
	while(fgets(word,SLEN,fp)==NULL)
        wordct++;
    rewind(fp);

    */

    printf("Please enter the word for this program:\n");
	while ((fscanf(stdin, "%s", word) == 1) && word[0] != '#')
		fprintf(fp, "%d.%s\n", ct++, word);

    rewind(fp);
    puts("Result displays at the following:");
	while ((ch = getc(fp)) != EOF)
		putc(ch, stdout);
	puts("\nDONE");
	fclose(fp);

	return 0;
}
