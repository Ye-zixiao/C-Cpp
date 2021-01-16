#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define SLEN 20
#define LINE 20
#define CROW 30
//bool ab(int n);

int main(void)
{
	FILE* fp;
	char file_name[SLEN];
	int numbers[LINE][CROW];
	int i, j;

	printf("Enter the name of file that you want to input: ");
	scanf("%s", file_name);
	if ((fp = fopen(file_name, "r")) == NULL)							//���ļ��е����ݷŵ�int�Ͷ�ά���鵱��
	{
		fprintf(stderr, "Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < LINE; i++)
		for (j = 0; j < CROW; j++)
			fscanf(fp, "%d", &numbers[i][j]);
	fclose(fp);

	/*for(i=0;i<LINE;i++)                                                        //����ȡ�ļ��������Ƿ���ȷ
        {
            for(j=0;j<CROW;j++)
                printf("%2d",numbers[i][j]);
            putchar('\n');
        }
	for(i=0;i<LINE;i++)
        for(j=0;j<CROW;j++)
        {
            if(i==0&&j==0)
            {
                if(ab(numbers[i][j]-numbers[i][j+1])&&ab(numbers[i][j]-numbers[i+1][j]))
                    numbers[i][j]=(numbers[i][j+1]+numbers[i][j+1])/2;
            }
            else if(i==0&&(j==CROW-1))
            {
                if(ab(numbers[i][j-1]-numbers[i][j])&&ab(numbers[i+1][j]-numbers[i][j]))
                    numbers[i][j]=(numbers[i][j-1]+numbers[i+1][j])/2;
            }
            else if(i==0&&j!=0&&(j!=CROW-1))
            {
                if(ab(numbers[i][j]-numbers[i][j+1])&&ab(numbers[i][j-1]-numbers[i][j])&&ab(numbers[i+1][j]-numbers[i][j]))
                    numbers[i][j]=(numbers[i][j-1]+numbers[i][j+1]+numbers[i+1][j])/3;
            }
            else if((i==LINE-1)&&(j==0))
            {
                if(ab(numbers[i][j]-numbers[i-1][j])&&ab(numbers[i][j]-numbers[i][j+1]))
                    numbers[i][j]=(numbers[i-1][j]+numbers[i][j+1])/2;
            }
            else if((i==LINE-1)&&(j==CROW-1))
            {
                if(ab(numbers[i][j]-numbers[i-1][j])&&ab(numbers[i][j]-numbers[i][j-1]))
                    numbers[i][j]=(numbers[i-1][j]+numbers[i][j-1])/2;
            }
            else if((i==LINE-1)&&(j!=CROW-1)&&(j!=0))
            {
                if(ab(numbers[i][j]-numbers[i-1][j])&&ab(numbers[i][j]-numbers[i][j-1])&&ab(numbers[i][j]-numbers[i][j+1]))
                    numbers[i][j]=(numbers[i-1][j]+numbers[i][j-1]+numbers[i][j+1])/3;
            }
            else if((i!=0)&&(i!=LINE-1)&&j==0)
            {
                if(ab(numbers[i][j]-numbers[i-1][j])&&ab(numbers[i][j]-numbers[i][j+1])&&ab(numbers[i][j]-numbers[i+1][j]))
                    numbers[i][j]=(numbers[i-1][j]+numbers[i][j+1]+numbers[i+1][j])/3;
            }
            else if(i!=0&&(i!=LINE-1)&&(j==CROW-1))
            {
                if(ab(numbers[i][j]-numbers[i-1][j])&&ab(numbers[i][j]-numbers[i][j-1])&&ab(numbers[i][j]-numbers[i+1][j]))
                    numbers[i][j]=(numbers[i-1][j]+numbers[i][j-1]+numbers[i+1][j])/3;
            }
            else
            {
                if(ab(numbers[i]-numbers[i-1][j])&&ab(numbers[i][j]-numbers[i][j-1])&&ab(numbers[i][j]-numbers[i][j+1])&&ab(numbers[i][j]-numbers[i+1][j]))
                    numbers[i][j]=(numbers[i-1][j]+numbers[i][j-1]+numbers[i][j+1]+numbers[i+1][j])/4;
            }
        }
        putchar('\n');
        putchar('\n');
        for(i=0;i<LINE;i++)                                                        //����ȡ�ļ��������Ƿ���ȷ
        {
            for(j=0;j<CROW;j++)
                printf("%2d",numbers[i][j]);
            putchar('\n');
        }*/

	char picture[LINE][CROW];											//��int�Ͷ�ά�����е�int����ת�����ַ����ݴ�ŵ���ά�ַ����鵱��
	for(i=0;i<LINE;i++)
		for (j = 0; j < CROW; j++)
		{
			switch (numbers[i][j])
			{
				case 0:
					picture[i][j] = ' ';
					break;
				case 1:
					picture[i][j] = '.';
					break;
				case 2:
					picture[i][j] = '\'';
					break;
				case 3:
					picture[i][j] = ':';
					break;
				case 4:
					picture[i][j] = '~';
					break;
				case 5:
					picture[i][j] = '*';
					break;
				case 6:
					picture[i][j] = '=';
					break;
				case 7:
					picture[i][j] = '&';
					break;
				case 8:
					picture[i][j] = '%';
					break;
				case 9:
					picture[i][j] = '#';
					break;
				default:
					break;
			}
		}

	printf("Enter the name of file to output: ");
	scanf("%s", file_name);
	if ((fp = fopen(file_name, "w")) == NULL)							//�����ļ������ַ����ݷŵ����ļ�����
	{
		fprintf(stderr, "Can't create file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < LINE; i++)											//������������ļ���ͬʱҲ�������������Ļ����
	{
		for (j = 0; j < CROW; j++)
		{
			putc(picture[i][j], stdout);
			putc(picture[i][j], fp);
		}
		putc('\n', stdout);
		putc('\n', fp);
	}
	fclose(fp);

	puts("\nDONE");
	return 0;

}
/*bool ab(int n)
{
    if(n<-1||n>1)
        return true;
    else
        return false;
}
*/
