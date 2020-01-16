#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 40

int main(int argc,char *argv[])
{
    FILE *in,*out;
    char ch;
    char name[LEN];
    int count=0;

    if(argc<2)
    {
        fprintf(stderr,"Usage: %s filename\n",argv[0]);
        exit(EXIT_FAILURE);                                 //程序异常中断
    }
    if((in=fopen(argv[1],"r"))==NULL)
    {
        fprintf(stderr,"I couldn't open the file\"%s\"\n",
                argv[1]);                                   //无法打开文件
        exit(EXIT_FAILURE);
    }

    strncpy(name,argv[1],LEN-5);

    char *pch;                                              //将.txt中的.换成空字符
    pch=strchr(name,'.');
    *pch='\0';

    name[LEN-5]='\0';                                       //防止文件名太长无法拼接上.red
    strcat(name,".red");                                    //设置好文件名
    if((out=fopen(name,"w"))==NULL)                         //无法创建文件eddy.txt.red则返回空指针
    {
        fprintf(stderr,"Can't create output file.\n");
        exit(3);
    }

    while((ch=getc(in))!=EOF)                               //输出压缩后的文件
        if(count++%3==0)
        {
            putc(ch,out);//输出字符到out文件指针所指向的文件
            putc(ch,stdout);//输出字符到标准输出文件（显示器上）
        }
    if(fclose(in)!=0||fclose(out)!=0)                       //关闭文件
        fprintf(stderr,"Error in closing files\n");

    return 0;
}

