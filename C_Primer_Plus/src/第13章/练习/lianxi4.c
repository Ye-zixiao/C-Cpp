#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    if(argc<=1)
    {
        fprintf(stderr,"Wrong usage!\n");
        exit(EXIT_FAILURE);
    }
    int i;
    FILE *fp;
    char ch;
    for(i=1;i<argc;i++)
    {
        fprintf(stdout,"File %d:\n",i);
        if((fp=fopen(argv[i],"r"))==NULL)
        {
            fprintf(stderr,"Can't open %s file.\n",argv[i]);
            exit(EXIT_FAILURE);
        }
        while((ch=getc(fp))!=EOF)
            putc(ch,stdout);
        putchar('\n');
        fclose(fp);
    }
    return 0;
}
