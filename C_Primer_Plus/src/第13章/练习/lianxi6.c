#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 20

int main(void)
{
	FILE* f_in, * f_out;
	char out_name[LEN];
	char in_name[LEN];
	char ch;
	int count=1;
	char* temp;

	printf("Enter the name of input: ");
	fscanf(stdin, "%s", in_name);
	strncpy(out_name, in_name, LEN - 5);
	temp = strchr(out_name, '.');
	*temp = '\0';
	strcat(out_name, ".red");
	if ((f_in = fopen(in_name, "r")) == NULL)
	{
		fprintf(stderr, "Can't open file %s\n", in_name);
		exit(EXIT_FAILURE);
	}
	if ((f_out = fopen(out_name, "w")) == NULL)
	{
		fprintf(stderr, "Can't open file %s\n", in_name);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(f_in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, f_out);

    /*while((ch=getc(f_out))!=EOF)
        putc(ch,stdout);*/
	fclose(f_out);
	fclose(f_in);
	puts("\nDone");

	return 0;
}
