#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 40

int main(int argc,char *argv[])
{
    FILE *in,*out;
    char ch;
    char name[LEN];
    int count=0;

    if(argc<2)
    {
        fprintf(stderr,"Usage: %s filename\n",argv[0]);
        exit(EXIT_FAILURE);                                 //�����쳣�ж�
    }
    if((in=fopen(argv[1],"r"))==NULL)
    {
        fprintf(stderr,"I couldn't open the file\"%s\"\n",
                argv[1]);                                   //�޷����ļ�
        exit(EXIT_FAILURE);
    }

    strncpy(name,argv[1],LEN-5);

    char *pch;                                              //��.txt�е�.���ɿ��ַ�
    pch=strchr(name,'.');
    *pch='\0';

    name[LEN-5]='\0';                                       //��ֹ�ļ���̫���޷�ƴ����.red
    strcat(name,".red");                                    //���ú��ļ���
    if((out=fopen(name,"w"))==NULL)                         //�޷������ļ�eddy.txt.red�򷵻ؿ�ָ��
    {
        fprintf(stderr,"Can't create output file.\n");
        exit(3);
    }

    while((ch=getc(in))!=EOF)                               //���ѹ������ļ�
        if(count++%3==0)
        {
            putc(ch,out);//����ַ���out�ļ�ָ����ָ����ļ�
            putc(ch,stdout);//����ַ�����׼����ļ�����ʾ���ϣ�
        }
    if(fclose(in)!=0||fclose(out)!=0)                       //�ر��ļ�
        fprintf(stderr,"Error in closing files\n");

    return 0;
}

