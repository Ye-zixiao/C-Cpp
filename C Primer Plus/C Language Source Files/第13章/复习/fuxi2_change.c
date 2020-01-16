#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    FILE *fp;
    double input;
    double sum=0;
    int ct=0;

    if(argc==1)
        fp=stdin;
    else if(argc==2)
    {
        if((fp=fopen(argv[1],"r"))==NULL)
        {
            fprintf(stderr,"Can't open %s file.\n",argv[1]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr,"Usage: fuxi2_change %s\n",argv[1]);
        exit(EXIT_FAILURE);
    }
    while((fscanf(fp,"%lf",&input)==1)&&input>=0)
    {
        sum+=input;
        ct++;
    }
    if(ct>0)
        fprintf(stdout,"The average of your input numbers is %.2f.\n",sum/ct);

    return 0;
}
