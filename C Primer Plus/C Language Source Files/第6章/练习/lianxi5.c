#include<stdio.h>//程序最大的问题就是变量太多了

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
		for (i = 1; i <= HANG; i++)            //控制行数
		{
			ch = input_ch;                  //将input_ch恢复成原始数（输入值-4）
			for (j = 1; j <= 5 - i; j++)         //制造空格
				printf(" ");
			for (k = 1; k < i; k++, ch++)       //升序制造字母
				printf("%c", ch);
			for (h = 1; h <= i; h++, ch--)      //降序制造字母
				printf("%c", ch);

			printf("\n");                 //打一行字母换一行
		}
		printf("Keep entering the aphabet\n");
		printf("(enter q to quit this program)\n");
		rv = scanf(" %c", &input_ch);		/*在这一步中我就遇到了scanf()函数吃
											掉回车键的典例，当第一次按下回车键的
											时候这个回车字符就一直保存在输入缓冲
											器当中，所以我使用了空格键来清除这个回车*/
	}

	return 0;
}

//当有发现了一个问题：这个scanf它不能通过按键来退出，因为ASCII码值在这个键盘上都是可以读出来的
