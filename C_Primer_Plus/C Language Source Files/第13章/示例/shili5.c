/*倒序显示文件的内容*/
#include<stdio.h>
#include<stdlib.h>
#define CNTL_Z '\032'
#define SLEN 81

int main(void)
{
    char file[SLEN];
    char ch;
    FILE *fp;
    long count,last;

    puts("Enter the name of the file to be processed:");
    scanf("%80s",file);
    if((fp=fopen(file,"rb"))==NULL)                 //以二进制模式打开文件
    {
        printf("reverse can't open %s\n",file);
        exit(EXIT_FAILURE);
    }

    fseek(fp,0L,SEEK_END);                          //fseek使得文件指针指向文件末尾的位置
    last=ftell(fp);                                 //ftell返回当前文件指针指向位置距离文件开头的大小
    for(count=1L;count<=last;count++)
    {
        fseek(fp,-count,SEEK_END);                  //重新使得fp指向下一个倒序位置
        ch=getc(fp);                                //读取这个文件指针所指向的字符
        if(ch!=CNTL_Z&&ch!='\r')
            putchar(ch);                            //输出字符然后count++更新文件指针
    }
    putchar('\n');

    fclose(fp);
    return 0;
}
