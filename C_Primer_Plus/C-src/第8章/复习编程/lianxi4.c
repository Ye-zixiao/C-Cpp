#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>

int main(void)
{
	char ch;
	bool first_flag = false;
	int alpha_ct = 0, word_ct = 0;

	printf("Enter the words that you want:\n");
	while ((ch = getchar()) != EOF)
	{
		if (isalpha(ch) && first_flag == false)							//�������ĸ
		{
			word_ct++;
			alpha_ct++;
			first_flag = true;
		}
		else if ((isalpha(ch) || ch == 39||ch=='-') && first_flag == true)		//��������ĸ����ĸ������-�͡�����⣩
		{
			if (isalpha(ch))
				alpha_ct++;
		}
		else
			first_flag = false;											//��⵽�հ׾ͽ���־λ������λΪfalse
	}
	printf("There are %d aphabets and %d words and average of a word is %0.2f\n",
		alpha_ct, word_ct, (double)alpha_ct / word_ct);

	return 0;
}
