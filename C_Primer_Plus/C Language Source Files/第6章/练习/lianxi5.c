#include<stdio.h>//��������������Ǳ���̫����

int main(void)
{
	const int HANG = 5;
	int i, j, k, h,rv;
	char ch, input_ch;

	printf("Enter a character for this program:\n");
	rv=scanf("%c", &input_ch);
	while (rv==1)
	{
		input_ch -= 4;
		for (i = 1; i <= HANG; i++)            //��������
		{
			ch = input_ch;                  //��input_ch�ָ���ԭʼ��������ֵ-4��
			for (j = 1; j <= 5 - i; j++)         //����ո�
				printf(" ");
			for (k = 1; k < i; k++, ch++)       //����������ĸ
				printf("%c", ch);
			for (h = 1; h <= i; h++, ch--)      //����������ĸ
				printf("%c", ch);

			printf("\n");                 //��һ����ĸ��һ��
		}
		printf("Keep entering the aphabet\n");
		printf("(enter q to quit this program)\n");
		rv = scanf(" %c", &input_ch);		/*����һ�����Ҿ�������scanf()������
											���س����ĵ���������һ�ΰ��»س�����
											ʱ������س��ַ���һֱ���������뻺��
											�����У�������ʹ���˿ո�����������س�*/
	}

	return 0;
}

//���з�����һ�����⣺���scanf������ͨ���������˳�����ΪASCII��ֵ����������϶��ǿ��Զ�������
