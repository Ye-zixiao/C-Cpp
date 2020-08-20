#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    FILE *fp;

    if(argc==1)
    {
        double input;
        double sum=0.0;
        int ct=0;

        printf("Enter the floating number for this program(q to quit):\n");
        while((scanf("%lf",&input)==1)&&input>=0.0)
        {
            sum+=input;
            ct++;
        }
        printf("The average of input numbers is %0.2f\n",sum/ct);
    }
    if(argc>=2)
    {
        int size;
        int i;
        double sum=0;
        char ch;
        double temp;

        printf("Enter the quality you want: ");
        scanf("%d",&size);
        if((fp=fopen(argv[1],"w"))==NULL)                               //以文本模式创建一个文件
        {
            fprintf(stderr,"Can't create %s file.\n",argv[1]);
            exit(EXIT_FAILURE);
        }
        for(i=0;i<size;i++)
        {
            scanf("%lf",&temp);
            sum+=temp;
        }
        fprintf(fp,"The average of your input numbers is %0.2f.\n",sum/size);
        fclose(fp);
        if((fp=fopen(argv[1],"r"))==NULL)                               //以文本模式打开这个文件
        {
            fprintf(stderr,"Can't open %s file.\n",argv[i]);
            exit(EXIT_FAILURE);
        }
        while((ch=getc(fp))!=EOF)
            putc(ch,stdout);
        fclose(fp);
    }

    return 0;
}
