#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZE 4096
#define SLEN 81
void append(FILE *source,FILE *dest);
char *s_gets(char *st,int n);

int main(void)
{
    FILE *fa,*fs;
    int files=0;
    char file_app[SLEN];                                            //目标文件名
    char file_src[SLEN];                                            //源文件名
    char ch;

    puts("Enter name of destination file:");
    s_gets(file_app,SLEN);                                          //读取目标文件名
    if((fa=fopen(file_app,"a+"))==NULL)                             //以更新模式打开文件
    {
        fprintf(stderr,"Can't open %s\n",stderr);
        exit(EXIT_FAILURE);
    }
    if(setvbuf(fa,NULL,_IOFBF,BUFSIZE)!=0)                          /*在使用时先用fopen函数打开文件，并在对流进行操作（读写）前，
                                                                    调用stevbuf为这个流设置自定义的缓冲区，这样可以减少内存向硬盘
                                                                    读写操作的次数，提高系统效率
                                                                    设置成NULL表示函数自己会为自己分配缓冲区*/
    {
        fputs("Can't create output buffer\n",stderr);
        exit(EXIT_FAILURE);
    }

    puts("Enter name of first source file (empty line to quit):");
    while(s_gets(file_src,SLEN)&&file_src[0]!='\0')                 //读取源文件名
    {
        if(strcmp(file_src,file_app)==0)                            //比较源文件名和目标文件名
            fputs("Can't append file to itself\n",stderr);
        else if((fs=fopen(file_src,"r"))==NULL)                     //如果两者文件名不同就打开源文件
            fprintf(stderr,"Can't open %s\n",file_src);
        else
        {
            if(setvbuf(fs,NULL,_IOFBF,BUFSIZE)!=0)                  //为源文件设置一个输入缓冲区，设置成NULL表示函数自己会为自己分配缓冲区
            {
                fputs("Can't create input buffer\n",stderr);
                continue;
            }
            append(fs,fa);
            if(ferror(fs)!=0)                                       /*在调用各种IO函数后可以使用ferror函数去检查。由于对同一文件每次调用IO函数
                                                                    均产生一个新的ferror函数值，因此在调用一个IO函数后应立即检查ferror的值，
                                                                    否则信息会丢失。在执行fopen函数时，ferror函数值自动置0*/
                fprintf(stderr,"Error in reading file %s.\n",file_src);
            if(ferror(fa)!=0)
                fprintf(stderr,"Error in writing file %s.\n",file_app);
            fclose(fs);
            files++;
            printf("File %s appended.\n",file_src);
            puts("Next source file (empty line to quit):");
        }
    }
    printf("Done appending.%d files appended.\n",files);
    rewind(fa);
    printf("%s contents:\n",file_app);
    while((ch=getc(fa))!=EOF)
        putchar(ch);
    fputc('\n',stdout);
    puts("Done displaying.");
    fclose(fa);

    return 0;
}

void append(FILE *source,FILE *dest)                                //将源文件的数据拷贝到目标文件
{
    size_t bytes;
    static char temp[BUFSIZE];

    while((bytes=fread(temp,sizeof(char),BUFSIZE,source))>0)        //从源文件中读取数据到数组temp
        fwrite(temp,sizeof(char),bytes,dest);                       //将数组中的数据写入到目标文件当中
}

char *s_gets(char *st,int n)
{
    char *ret_val;
    char *find;

    ret_val=fgets(st,n,stdin);                              /*如果输入长度超过了n，那么数组中就只会在末尾加上一个空指针
                                                            ，如果没有超过这个长度必然会在空指针的前面引入一个换行符*/
    if(ret_val)                                             //这个if语句块就是为了消除这个换行符
    {
        find=strchr(st,'\n');
        if(find)
            *find='\0';
        else
            while(getchar()!='\n')
                continue;
    }
    return ret_val;
}
