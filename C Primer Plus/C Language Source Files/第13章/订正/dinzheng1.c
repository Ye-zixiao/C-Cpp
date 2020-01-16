#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        fprintf(stderr,"Wrong Usage\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        FILE *fs;
        FILE *ft;
        char ch;

        if((fs=fopen(argv[1],"rb"))==NULL)
        {
            fprintf(stderr,"Can't open file %s\n",argv[1]);
            exit(EXIT_FAILURE);
        }
        if((ft=fopen(argv[2],"wb"))==NULL)
        {
            fprintf(stderr,"Can't create file %s\n",argv[2]);
            exit(EXIT_FAILURE);
        }
        while((ch=getc(fs))!=EOF)
        {
            putc(ch,ft);
        }

        fclose(ft);
        fclose(fs);
    }

    puts("DONE");
    return 0;
}
