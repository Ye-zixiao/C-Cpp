#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define BUFSIZE 1024
void copy_file(FILE *fs,FILE *ft);

int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        fprintf(stderr,"Usage: program_name %s\n",argv[1]);
        exit(EXIT_FAILURE);
    }
    else
    {
        FILE *fs;
        FILE *ft;
        if((fs=fopen(argv[1],"r+"))==NULL)
        {
            fprintf(stderr,"Can't open %s file.\n",argv[1]);
            exit(EXIT_FAILURE);
        }
        if((ft=fopen(argv[2],"a+"))==NULL)
        {
            fprintf(stderr,"Can't create %s file.\n",argv[1]);
            exit(EXIT_FAILURE);
        }
        copy_file(fs,ft);
        char ch;
        while((ch=getc(ft))!=EOF)
            putc(ch,stdout);

        fclose(fs);
        fclose(ft);
        return 0;
    }
}

void copy_file(FILE *fs,FILE *ft)//用fgets函数试试
{
    int i=0;
    char temp[BUFSIZE];
    char *count=temp;

    while(fgets(temp,BUFSIZE,fs)!=NULL)
    {
        while(count[i]!='\n')
        {
            if(isalpha(count[i]))
                count[i]=toupper(count[i]);
            i++;
        }
        fwrite(temp,sizeof(char),i,ft);
    }
}



/*if(setvbuf(fp,NULL,_IOFBF,BUFSIZE)!=0)
        {
            fprintf(stderr,"Can't create buffer for this program.\n");
            exit(EXIT_FAILURE);
        }*/
