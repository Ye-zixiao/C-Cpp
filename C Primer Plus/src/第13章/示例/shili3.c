#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 41

int main(void)
{
    FILE *fp;
    char words[MAX];

    if((fp=fopen("eddy.txt","a+"))==NULL)                   //����ļ��Ƿ�򿪣��Ը���ģʽ�򿪣�
    {
        fprintf(stdout,"Can't open \"eddy.txt\" file.\n");
        exit(EXIT_FAILURE);
    }

    puts("Enter words to add to the file;press the #");
    puts("key at the beginning of a line to terminate.");
    while((fscanf(stdin,"%40s",words)==1)&&(words[0]!='#'))//�ӱ�׼�����ȡһ���ַ��������ǵ�һ���ַ���#��
        fprintf(fp,"%s\n",words);                           //����׼����õ����ַ��������fp�ļ�ָ��ָ����ļ�����

    puts("File contents:");
    rewind(fp);                                             //����ص��ļ��Ŀ�ʼ��
    /*���϶����ļ�eddy.txt�����ϴ�����ϣ�ֻʣ�½��ļ��е��ַ����������*/
    while(fscanf(fp,"%s",words)==1)                         //��fp�ļ�ָ��ָ����ַ�����ȡ��words������鵱��
        puts(words);                                        //Ȼ��ֱ�����
    puts("Done!");
    if(fclose(fp)!=0)                                       //�ر��ļ�
        fprintf(stderr,"Error closing file\n");

    return 0;
}
