#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 256

int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        fprintf(stderr,"Wrong input usage.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        char ch_cmp=argv[1][0];
        char temp[SIZE];
        FILE *fp;

        if((fp=fopen(argv[2],"r"))==NULL)
        {
            fprintf(stderr,"Can't open %s file.\n",argv[2]);
            exit(EXIT_FAILURE);
        }
        int ct=0;                                           //ʹ��fgets������������Ϊfgets��������з���EOF�Լ�����ַ�����ֹͣ
        while(fgets(temp,SIZE,fp)!=NULL)                    //ע�⣺�ļ���β��ʵ�����ļ�ĩβ����һ�еĿ�ͷ���Լ���Ctrl+Z��ʱ����һ��
        {
            if(strchr(temp,ch_cmp)!=NULL)                   //��strchr�ҳ������ַ������ҵ���ӡ����
            {
                fputs(temp,stdout);
                ct++;
            }
        }
        fprintf(stdout,"There are %d line(s) need to print.\n",ct);

        fclose(fp);
    }

    return 0;
}
