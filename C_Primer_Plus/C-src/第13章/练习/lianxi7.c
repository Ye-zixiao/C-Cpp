#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int main(int argc, char* argv[])//文件1 文件2
{
	FILE* fp1, * fp2;
	char ch;
	bool flag_1, flag_2;
	flag_1 = flag_2 = false;

	if (argc != 3)
	{
		fputs("Wrong Usage\n", stderr);
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((fp1 = fopen(argv[1], "r")) == NULL)
		{
			fprintf(stderr,"Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		if ((fp2 = fopen(argv[2], "r")) == NULL)
		{
			fprintf(stderr,"Can't open file %s\n", argv[2]);
			exit(EXIT_FAILURE);
		}
		while (!flag_1||!flag_2)                                //用标志位去判定是否某一文件打印完毕
		{
			if (!flag_1)
			{
				while ((ch = getc(fp1)) != EOF && ch != '\n')
					putc(ch,stdout);
				putchar('\n');
				if (ch == EOF)
					flag_1 = true;                              //如果读取到EOF就将flag位置为ture，这样就不会再打印这个文件中的数据
			}
			if (!flag_2)
			{
				while ((ch = getc(fp2)) != EOF && ch != '\n')
					putc(ch, stdout);
				putchar('\n');
				if (ch == EOF)
					flag_2 = true;
			}
		}

		puts("\nDone");
		fclose(fp1);
		fclose(fp2);
		return 0;
	}
}
