#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 256

int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        fprintf(stderr,"Wrong input usage.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        char ch_cmp=argv[1][0];
        char temp[SIZE];
        FILE *fp;

        if((fp=fopen(argv[2],"r"))==NULL)
        {
            fprintf(stderr,"Can't open %s file.\n",argv[2]);
            exit(EXIT_FAILURE);
        }
        int ct=0;                                           //使用fgets（）函数是因为fgets会读到换行符和EOF以及最大字符数后停止
        while(fgets(temp,SIZE,fp)!=NULL)                    //注意：文件结尾其实是在文件末尾的下一行的开头，自己按Ctrl+Z的时候想一下
        {
            if(strchr(temp,ch_cmp)!=NULL)                   //用strchr找出期望字符，如找到打印该行
            {
                fputs(temp,stdout);
                ct++;
            }
        }
        fprintf(stdout,"There are %d line(s) need to print.\n",ct);

        fclose(fp);
    }

    return 0;
}
