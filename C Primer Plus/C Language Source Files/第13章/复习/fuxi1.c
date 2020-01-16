#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc,char *argv[])
{
    char ch;
    FILE *fp;
    if(argc<2)
        exit(EXIT_FAILURE);
    if((fp=fopen(argv[1],"r"))==NULL)
        exit(EXIT_FAILURE);
    while((ch=getc(fp))!=EOF)
        if(isdigit(ch))
            putc(ch,stdout);
    fclose(fp);

    return 0;
}
