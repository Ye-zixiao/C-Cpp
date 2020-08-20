#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 81
#define RANGE 100

int main(void)
{
	int words_num;
	char temp[SIZE];
	char* words[RANGE];//二级指针也需要用malloc函数去向内存要空间
	int i;

	printf("How many words do you wish to enter? ");
	scanf("%d", &words_num);
	printf("Enter %d words now:\n", words_num);
	for (i = 0; i < words_num; i++)
	{
		scanf("%s", temp);
		words[i] = (char*)malloc(strlen(temp) + 1);
		strcpy(words[i], temp);
	}

    printf("Here are your words:\n");
	for (i = 0; i < words_num; i++)
		puts(words[i]);
	for (i = 0; i < words_num; i++)
		free(words[i]);

	return 0;
}
