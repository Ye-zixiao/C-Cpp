#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    char ch;
    FILE *fp;
    int count=0;
    if(argc!=2)
    {
        printf("Usage:%s filename\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    if((fp=fopen(argv[1],"r"))==NULL)//����û�д��ļ�argv[1]��������ļ��ͷ���һ����ָ��
    {
        printf("Can't open %s\n",argv[1]);
        exit(EXIT_FAILURE);
    }
    while((ch=getc(fp))!=EOF)           //��ȡfp��ָ����ļ����ַ�
    {
        putc(ch,stdout);                //����ļ��е��ַ�����׼�������ʾ���ϣ�
        count++;
    }
    putc('\n',stdout);

    fclose(fp);
    printf("File %s has %d characters\n",argv[1],count);

    return 0;
}
