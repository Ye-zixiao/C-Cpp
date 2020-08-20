#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define LIM 10
#define SIZE 81
char* s_gets(char* st, int n);
void all_upper(char* st[], int string_ct);
void print_initial(char* st[], int string_ct);

int main(int argc, char* argv[])
{
	char input[LIM][SIZE];
	char* ptr[LIM];

	puts("Enter the strings for this program");
	int ct = 0;
	while (s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0' && ct < SIZE)
	{
		ptr[ct] = input[ct];
		ct++;
	}

	if (argc > 2)
		puts("Enter the right form for this program:");
	else if (argc == 2)
	{
		if (!strcmp(argv[1], "-p"))
			print_initial(ptr, ct);
		else if (!strcmp(argv[1], "-u"))
			all_upper(ptr, ct);
		else
			puts("Enter the right form for this program.");
	}
	puts("Done");
}

char* s_gets(char* st, int n)                              //输入字符串
{
	char* ret_val;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (*st != '\n' && *st != '\0')
			st++;
		if (*st == '\n')
			* st = '\0';
		else
			while (getchar() != '\n')
				continue;
		/* char *find;
			find=strchr(st,'\n');
			if(find)
				*find='\0';
			else
				while(getchar()!='\n')
					continue;
			*/
	}
	return ret_val;
}

void all_upper(char* st[], int string_ct)                   //大写输出
{
	int i;
	for (i = 0; i < string_ct; i++)
	{
		while (*st[i] != '\0')
		{
			putchar(toupper(*st[i]));
			st[i]++;
		}
		putchar('\n');
	}
}


void print_initial(char* st[], int string_ct)              //原始输出
{
	int i;
	for (i = 0; i < string_ct; i++)
		puts(st[i]);
}
