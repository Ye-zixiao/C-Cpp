#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[])
{
	FILE* fp;
	char ch;
	char ch_cmp;
	int i;
	int ct;

	if (argc < 2)
	{
		fprintf(stderr, "Wrong Usage\n");
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		ch_cmp = argv[1][0];
		fp = stdin;
		ct = 0;
		while ((ch = getc(fp)) != EOF)
		{
			putc(ch, stdout);
			if (ch == ch_cmp)
				ct++;
		}
		printf("\nThere are %d character '%c' in your input\n", ct, ch_cmp);
	}
	else
	{
		ch_cmp = argv[1][0];
		for (i = 2; i < argc; i++)
		{
			ct = 0;
			if ((fp = fopen(argv[i], "r")) == NULL)
			{
				fprintf(stderr, "Can't open file %s\n", argv[i]);
				i++;
				continue;
			}
			while ((ch = getc(fp)) != EOF)
			{
				putc(ch, stdout);
				if (ch == ch_cmp)
					ct++;
			}
			printf("\nThere are %d character '%c' in file %s\n", ct, ch_cmp, argv[i]);
			fclose(fp);
		}
	}
	puts("Done");

	return 0;
}
