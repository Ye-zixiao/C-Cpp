/* ������P236��237��238��239�ĳ�����޸�1�����������scanf�����������ִ����Ļ��з����⣬
ȱ�㣺count�������ܴ���������ַ�*/
#include<stdio.h>
char get_choice(void);
void count(void);
char get_first(void);

int main(void)
{
	char choice;

	printf("Please choice: \n");
	while ((choice = get_choice()) != 'q')
	{
		switch (choice)
		{
			case 'a':
				printf("Buy low,sell high.\n");
				break;
			case 'b':
				putchar('\a');
				break;
			case 'c':
				count();
				break;
			case '\n':
				printf("Program error.\n");
				break;
		}
		printf("Rechoice:\n");
	}
	printf("Done.\n");

	return 0;
}

char get_choice(void)
{
	char ch;

	printf("Enter the letter of your choice:\n");
	printf("a) advice           b) bell\n");
	printf("c) count            q) quit\n");
	ch = get_first();
	while ((ch<'a' || ch>'c') && ch != 'q')
	{
		printf("Please respond with a,b,c, or q.\n");
		ch = get_first();
	}

	return ch;
}

void count(void)
{
	int n, i;
	printf("Count how far?Enter an integer:\n");
	scanf("%d", &n);                                //�����и�ȱ�㣺���ܶԷ����ֵ��ַ����д���
	for (i = 1; i <= n; i++)
		printf("%d\n", i);
}

char get_first(void)
{
	char ch;

	while ((ch = getchar()) == '\n')			//�жϵ�һ�������Ƿ�Ϊ���з��������ٴζ�ȡ��ֱ����ȡ�Ĳ��ǻ��з�
		continue;

	while (getchar() != '\n')
		continue;

	return ch;
}
/*������е�P236��P237��
��Ȼ����˵����P237���ڲ����޸ĵ�����£����г���ѡ��cȻ�����scanf()��������������+ENTER�������˻��з�'\n'
���ٴλس���get_first()��ch = getchar()��ȡ������������뻺�����еĻ��з��������ڽ����������е�������'\n'��
ASCII����10С��'a'����while ((ch<'a' || ch>'c') && ch != 'q'&&ch!='\n')�Ĳ��Ա��ʽ���ͽ��������ѭ���嵱��
�������Please respond with a,b,c, or q. Ȼ���ֵȴ����롣�������Ǿͼ�����Program error.��仰��
	���Ҫ������仰����Ҫ��while ((ch<'a' || ch>'c') && ch != 'q'&&ch!='\n')�еĲ��Ա��ʽ���м���&&ch!='\n'
�������Ǿ��ܼ�����������ˣ�����Ҳ�ܺõ�չʾ��scanf������getchar����һ��ʹ�ã����б���Ϊ����ַ���������������
��ʱ������*/
