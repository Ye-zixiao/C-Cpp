#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#define SIZE 81
char* find(const char* st1, const char* st2);

int main(void)
{
	char orig[SIZE] = "hats";

	char* isfind = NULL;
	isfind = find(orig, "at");
	printf("%p\n", isfind);
	if (isfind)
		puts("find");
	else
		puts("no");

	return 0;
}

char* find(const char* st1, const char* st2)
{
	int tar_length = strlen(st2);
	int seek_length;                //至少要找这个长度
	seek_length = strlen(st1) - tar_length + 1;
	int nofind = 1;

	if (seek_length > 0)
	{
		printf("seek_length=%d\n", seek_length);
		while (seek_length&&(nofind = strncmp(st1, st2, tar_length)))//这个程序还是有很多缺点的
		{
			printf("seek_length=%d\n", seek_length);
			printf("nofind=%d\n", nofind);
			st1++;
			seek_length--;
			putchar('\n');
		}
		printf("nofind=%d\n", nofind);
	}
	if (nofind)
	{
		puts("no");
		return NULL;
	}
	else
	{
		puts("find");
		return (char*)st1;
	}
}
