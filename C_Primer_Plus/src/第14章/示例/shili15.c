#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define LEN 30

char* s_gets(char* st, int n);

enum spetrum {red,orange,yellow,green,blue,violet};					//������һ��ö������
const char* colors[] = { "red","orange","yellow",					//������һ��ָ�����飬�ֱ�ָ����Ե��ַ�����
						"green","blue","violet" };

int main(void)
{
	char choice[LEN];
	enum spetrum color;												//������һ��ö�ٱ���
	bool color_is_found = false;									//��־

	puts("Enter a color (empty line to quit):");
	while (s_gets(choice, LEN) != NULL && choice[0] != '\0')
	{
		for (color = red; color <= violet; color++)					//��������ַ���������е��ַ����������бȽϣ��ҳ��Ǹ��ַ���������ҵ��ͽ���־λ��Ϊtrue
		{
			if (strcmp(choice, colors[color]) == 0)
			{
				color_is_found = true;
				break;
			}
		}

		if (color_is_found)											//���ҵ�������switch����д�ӡ���
			switch (color)
			{
			case red:
				puts("Rose is red.");
				break;
			case orange:
				puts("Poppies are orange.");
				break;
			case yellow:
				puts("Sunflowers are yellow.");
				break;
			case green:
				puts("Grass is green,");
				break;
			case blue:
				puts("Bluebells are blue.");
				break;
			case violet:
				puts("Violets are violet.");
				break;
			}
		else
			printf("I don't know  about the color %s\n", choice);
		color_is_found = false;									//���½���־λ��Ϊfalse
		puts("Next color,please (empty line to quit):");
	}

	puts("Goodbye.");

	return 0;
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			* find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
