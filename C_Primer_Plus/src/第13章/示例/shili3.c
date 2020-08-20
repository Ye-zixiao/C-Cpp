#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 41

int main(void)
{
    FILE *fp;
    char words[MAX];

    if((fp=fopen("eddy.txt","a+"))==NULL)                   //检查文件是否打开（以更新模式打开）
    {
        fprintf(stdout,"Can't open \"eddy.txt\" file.\n");
        exit(EXIT_FAILURE);
    }

    puts("Enter words to add to the file;press the #");
    puts("key at the beginning of a line to terminate.");
    while((fscanf(stdin,"%40s",words)==1)&&(words[0]!='#'))//从标准输入读取一个字符串，除非第一个字符是#号
        fprintf(fp,"%s\n",words);                           //将标准输入得到的字符串输出到fp文件指针指向的文件当中

    puts("File contents:");
    rewind(fp);                                             //程序回到文件的开始处
    /*以上对于文件eddy.txt基本上处理完毕，只剩下将文件中的字符串输出工作*/
    while(fscanf(fp,"%s",words)==1)                         //将fp文件指针指向的字符串读取到words这个数组当中
        puts(words);                                        //然后直接输出
    puts("Done!");
    if(fclose(fp)!=0)                                       //关闭文件
        fprintf(stderr,"Error closing file\n");

    return 0;
}
