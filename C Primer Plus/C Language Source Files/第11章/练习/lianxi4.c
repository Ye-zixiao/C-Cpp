#include<stdio.h>
#include<ctype.h>
#define SIZE 10
void storeword(char* str, int max);

int main(void)
{
	char input[SIZE];
	storeword(input, SIZE - 1);
	puts(input);

	return 0;
}

void storeword(char* str, int max)                   //max�Ƕ�ȡ���ʵ��������
{
	char ch;
	int ct = 0;

	while (isspace(ch = getchar()))
		continue;
	do
	{
		*str = ch;                                    //�Ƚ���һ��ѭ�����ַ���ȡ�����鵱��
		str++;
		ct++;
	} while (!isspace(ch = getchar()) && ct <= max-1);       /*������ǿհ��ַ��Ҿͼ��������뻺�����ж�ȡ�ַ���
														ȱ�㣺getchar��Ե�һ�����з���������ֻ��һ�����ʵ������*/
	*str = '\0';                                    //����������λ�÷�һ�����ַ�
	if(ch!='\n')                                            //�����ͷ�ֹ�Ե��س�����Ҫ������һ���ַ�
		while (getchar() != '\n')
			continue;
}
