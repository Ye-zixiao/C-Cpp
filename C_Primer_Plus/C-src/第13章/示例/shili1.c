#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    char ch;
    FILE *fp;
    int count=0;
    if(argc!=2)
    {
        printf("Usage:%s filename\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    if((fp=fopen(argv[1],"r"))==NULL)//弱国没有打开文件argv[1]所代表的文件就返回一个空指针
    {
        printf("Can't open %s\n",argv[1]);
        exit(EXIT_FAILURE);
    }
    while((ch=getc(fp))!=EOF)           //读取fp所指向的文件的字符
    {
        putc(ch,stdout);                //输出文件中的字符到标准输出（显示器上）
        count++;
    }
    putc('\n',stdout);

    fclose(fp);
    printf("File %s has %d characters\n",argv[1],count);

    return 0;
}
