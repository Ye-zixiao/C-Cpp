#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool ab(int n);

int main(void)
{
	FILE* fp;
	int lines, crows;
	int (*num_arr)[20];
	char (*char_arr)[20];
	char *name_arr;
	int n;
	int i,j;

	printf("Enter the range number of filename: ");
	scanf("%d", &n);
	name_arr = (char*)malloc(n * sizeof(char));
	printf("Enter the name of file that you want to input: ");
	scanf("%s", name_arr);
	if ((fp = fopen(name_arr, "r")) == NULL)
	{
		fprintf(stderr, "Can't open file %s\n", name_arr);
		exit(EXIT_FAILURE);
	}

	printf("Enter the number of lines and crows: ");                            //将文件中的数据装入到int数组当中
	scanf("%d %d", &lines, &crows);
	num_arr=(int (*)[20])malloc(20*crows*sizeof(int));
	char_arr=(char (*)[20])malloc(20*crows*sizeof(char));
	for(i=0;i<lines;i++)                                                        /*用打印的方法去检验*/
        for(j=0;j<crows;j++)
            fscanf(fp,"%d",&num_arr[i][j]);//搞不明白为什么读错
    fclose(fp);

    for(i=0;i<lines;i++)                                                        //检查读取文件的数据是否正确
    {
        for(j=0;j<crows;j++)
            printf("%2d",num_arr[i][j]);
        putchar('\n');
    }

    for(i=0;i<lines;i++)
        for(j=0;j<crows;j++)
        {
            if(i==0&&j==0)
            {
                if(ab(num_arr[i][j]-num_arr[i][j+1])&&ab(num_arr[i][j]-num_arr[i+1][j]))
                    num_arr[i][j]=(num_arr[i][j+1]+num_arr[i][j+1])/2;
            }
            else if(i==0&&(j==crows-1))
            {
                if(ab(num_arr[i][j-1]-num_arr[i][j])&&ab(num_arr[i+1][j]-num_arr[i][j]))
                    num_arr[i][j]=(num_arr[i][j-1]+num_arr[i+1][j])/2;
            }
            else if(i==0&&j!=0&&(j!=crows-1))
            {
                if(ab(num_arr[i][j]-num_arr[i][j+1])&&ab(num_arr[i][j-1]-num_arr[i][j])&&ab(num_arr[i+1][j]-num_arr[i][j]))
                    num_arr[i][j]=(num_arr[i][j-1]+num_arr[i][j+1]+num_arr[i+1][j])/3;
            }
            else if((i==lines-1)&&(j==0))
            {
                if(ab(num_arr[i][j]-num_arr[i-1][j])&&ab(num_arr[i][j]-num_arr[i][j+1]))
                    num_arr[i][j]=(num_arr[i-1][j]+num_arr[i][j+1])/2;
            }
            else if((i==lines-1)&&(j==crows-1))
            {
                if(ab(num_arr[i][j]-num_arr[i-1][j])&&ab(num_arr[i][j]-num_arr[i][j-1]))
                    num_arr[i][j]=(num_arr[i-1][j]+num_arr[i][j-1])/2;
            }
            else if((i==lines-1)&&(j!=crows-1)&&(j!=0))
            {
                if(ab(num_arr[i][j]-num_arr[i-1][j])&&ab(num_arr[i][j]-num_arr[i][j-1])&&ab(num_arr[i][j]-num_arr[i][j+1]))
                    num_arr[i][j]=(num_arr[i-1][j]+num_arr[i][j-1]+num_arr[i][j+1])/3;
            }
            else if((i!=0)&&(i!=lines-1)&&j==0)
            {
                if(ab(num_arr[i][j]-num_arr[i-1][j])&&ab(num_arr[i][j]-num_arr[i][j+1])&&ab(num_arr[i][j]-num_arr[i+1][j]))
                    num_arr[i][j]=(num_arr[i-1][j]+num_arr[i][j+1]+num_arr[i+1][j])/3;
            }
            else if(i!=0&&(i!=lines-1)&&(j==crows-1))
            {
                if(ab(num_arr[i][j]-num_arr[i-1][j])&&ab(num_arr[i][j]-num_arr[i][j-1])&&ab(num_arr[i][j]-num_arr[i+1][j]))
                    num_arr[i][j]=(num_arr[i-1][j]+num_arr[i][j-1]+num_arr[i+1][j])/3;
            }
            else
            {
                if(ab(num_arr[i]-num_arr[i-1][j])&&ab(num_arr[i][j]-num_arr[i][j-1])&&ab(num_arr[i][j]-num_arr[i][j+1])&&ab(num_arr[i][j]-num_arr[i+1][j]))
                    num_arr[i][j]=(num_arr[i-1][j]+num_arr[i][j-1]+num_arr[i][j+1]+num_arr[i+1][j])/4;
            }
        }
        putchar('\n');
        putchar('\n');
        for(i=0;i<lines;i++)                                                        //检查读取文件的数据是否正确
        {
            for(j=0;j<crows;j++)
                printf("%2d",num_arr[i][j]);
            putchar('\n');
        }




    for(i=0;i<lines;i++)                                                        //将数字数组的数字转化成字符型数据存储到二维数组当中
        for(j=0;j<crows;j++)
        {
            switch(num_arr[i][j])
            {
                case 0:
                    char_arr[i][j]=' ';
                    break;
                case 1:
                    char_arr[i][j]='.';
                    break;
                case 2:
                    char_arr[i][j]='\'';
                    break;
                case 3:
                    char_arr[i][j]=':';
                    break;
                case 4:
                    char_arr[i][j]='~';
                    break;
                case 5:
                    char_arr[i][j]='*';
                    break;
                case 6:
                    char_arr[i][j]='=';
                    break;
                case 7:
                    char_arr[i][j]='&';
                    break;
                case 8:
                    char_arr[i][j]='%';
                    break;
                case 9:
                    char_arr[i][j]='#';
                    break;
                default:
                    break;
            }
        }

    printf("test\n");                                                           //检查程序是否运行到了这里
    printf("Enter the name of output file: ");
    scanf("%s",name_arr);
    if((fp=fopen(name_arr,"w"))==NULL)                                          //创建文件输出并打印数据
    {
        fprintf(stderr,"Can't create file %s\n",name_arr);
        exit(EXIT_FAILURE);
    }
    for(i=0;i<lines;i++)
    {
        for(j=0;j<crows;j++)
        {
            putc(char_arr[i][j],stdout);
            putc(char_arr[i][j],fp);
        }
        putc('|',stdout);
        putc('\n',stdout);
        putc('\n',fp);
    }
    fclose(fp);
    puts("\nDONE");

    free(name_arr);
    free(num_arr);
    free(char_arr);

    return 0;
}

bool ab(int n)
{
    if(n<-1||n>1)
        return true;
    else
        return false;
}
