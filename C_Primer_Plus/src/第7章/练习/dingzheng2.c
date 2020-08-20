#include<stdio.h>
int main(void)
{
	char ch;
	int ju_ct = 0, gt_ct = 0;

	printf("Enter the words for this program\n");
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
			case '.':
				putchar('!');
				ju_ct++;
				break;
			case '!':
				putchar('!');
				putchar('!');
				gt_ct++;
				break;
			default:
				putchar(ch);
		}
	}
	printf("\n");
	printf("%d %s replaced\n", ju_ct, ju_ct > 1 ? "juhaos" : "juhao");
	printf("%d %s replaced\n", gt_ct, gt_ct > 1 ? "gantanhaos" : "gantan");

	return 0;
}
