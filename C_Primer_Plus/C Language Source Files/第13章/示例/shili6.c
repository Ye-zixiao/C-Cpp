#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    FILE *fp;
    if((fp=fopen("eddy.txt","r"))==NULL)
    {
        fprintf(stderr,"not open this file\n");
        exit(EXIT_FAILURE);
    }
    if(fflush(stdout)==NULL)
        printf("clear all\n");
    if(fclose(fp)!=0)
        fprintf(stderr,"not close this file\n");

    return 0;
}
