#include<stdio.h>
#include<stdlib.h>
#define BUFSIZE 1024

void copy_file(FILE *source,FILE *target);

int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        fprintf(stderr,"Wrong Usage.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        FILE *fs;
        FILE *ft;
        char ch;

        if((fs=fopen(argv[1],"rb"))==NULL)
        {
            fprintf(stderr,"Can't open %s file.\n",argv[1]);
            exit(EXIT_FAILURE);
        }
        if(setvbuf(fs,NULL,_IOFBF,BUFSIZE)!=0)
        {
            fprintf(stderr,"Can't create input buffer.\n");
            exit(EXIT_FAILURE);
        }
        if((ft=fopen(argv[2],"wb"))==NULL)
        {
            fprintf(stderr,"Can't open %s file.\n",argv[2]);
            exit(EXIT_FAILURE);
        }
        if(setvbuf(ft,NULL,_IOFBF,BUFSIZE)!=0)
        {
            fprintf(stderr,"Can't create output buffer.\n");
            exit(EXIT_FAILURE);
        }
        //对文件进行操作
        copy_file(fs,ft);
        /*if(ferror(ft)==0)
        {
            fprintf(stderr,"Can't read and write.\n");
            exit(EXIT_FAILURE);
        }*/
        fclose(fs);
        fclose(ft);
        ft=fopen(argv[2],"r");
        while((ch=getc(ft))!=EOF)
            putc(ch,stdout);

        fclose(ft);

        return 0;
    }
}

void copy_file(FILE *source,FILE *target)
{
    int temp[BUFSIZE];
    int size;

    while((size=fread(temp,sizeof(int),BUFSIZE,source))>0)
        fwrite(temp,sizeof(int),size,target);
}
