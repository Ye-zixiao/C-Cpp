/*������ʾ�ļ�������*/
#include<stdio.h>
#include<stdlib.h>
#define CNTL_Z '\032'
#define SLEN 81

int main(void)
{
    char file[SLEN];
    char ch;
    FILE *fp;
    long count,last;

    puts("Enter the name of the file to be processed:");
    scanf("%80s",file);
    if((fp=fopen(file,"rb"))==NULL)                 //�Զ�����ģʽ���ļ�
    {
        printf("reverse can't open %s\n",file);
        exit(EXIT_FAILURE);
    }

    fseek(fp,0L,SEEK_END);                          //fseekʹ���ļ�ָ��ָ���ļ�ĩβ��λ��
    last=ftell(fp);                                 //ftell���ص�ǰ�ļ�ָ��ָ��λ�þ����ļ���ͷ�Ĵ�С
    for(count=1L;count<=last;count++)
    {
        fseek(fp,-count,SEEK_END);                  //����ʹ��fpָ����һ������λ��
        ch=getc(fp);                                //��ȡ����ļ�ָ����ָ����ַ�
        if(ch!=CNTL_Z&&ch!='\r')
            putchar(ch);                            //����ַ�Ȼ��count++�����ļ�ָ��
    }
    putchar('\n');

    fclose(fp);
    return 0;
}
