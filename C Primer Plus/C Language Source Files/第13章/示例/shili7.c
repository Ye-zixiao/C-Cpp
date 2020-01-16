#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZE 4096
#define SLEN 81
void append(FILE *source,FILE *dest);
char *s_gets(char *st,int n);

int main(void)
{
    FILE *fa,*fs;
    int files=0;
    char file_app[SLEN];                                            //Ŀ���ļ���
    char file_src[SLEN];                                            //Դ�ļ���
    char ch;

    puts("Enter name of destination file:");
    s_gets(file_app,SLEN);                                          //��ȡĿ���ļ���
    if((fa=fopen(file_app,"a+"))==NULL)                             //�Ը���ģʽ���ļ�
    {
        fprintf(stderr,"Can't open %s\n",stderr);
        exit(EXIT_FAILURE);
    }
    if(setvbuf(fa,NULL,_IOFBF,BUFSIZE)!=0)                          /*��ʹ��ʱ����fopen�������ļ������ڶ������в�������д��ǰ��
                                                                    ����stevbufΪ����������Զ���Ļ��������������Լ����ڴ���Ӳ��
                                                                    ��д�����Ĵ��������ϵͳЧ��
                                                                    ���ó�NULL��ʾ�����Լ���Ϊ�Լ����仺����*/
    {
        fputs("Can't create output buffer\n",stderr);
        exit(EXIT_FAILURE);
    }

    puts("Enter name of first source file (empty line to quit):");
    while(s_gets(file_src,SLEN)&&file_src[0]!='\0')                 //��ȡԴ�ļ���
    {
        if(strcmp(file_src,file_app)==0)                            //�Ƚ�Դ�ļ�����Ŀ���ļ���
            fputs("Can't append file to itself\n",stderr);
        else if((fs=fopen(file_src,"r"))==NULL)                     //��������ļ�����ͬ�ʹ�Դ�ļ�
            fprintf(stderr,"Can't open %s\n",file_src);
        else
        {
            if(setvbuf(fs,NULL,_IOFBF,BUFSIZE)!=0)                  //ΪԴ�ļ�����һ�����뻺���������ó�NULL��ʾ�����Լ���Ϊ�Լ����仺����
            {
                fputs("Can't create input buffer\n",stderr);
                continue;
            }
            append(fs,fa);
            if(ferror(fs)!=0)                                       /*�ڵ��ø���IO���������ʹ��ferror����ȥ��顣���ڶ�ͬһ�ļ�ÿ�ε���IO����
                                                                    ������һ���µ�ferror����ֵ������ڵ���һ��IO������Ӧ�������ferror��ֵ��
                                                                    ������Ϣ�ᶪʧ����ִ��fopen����ʱ��ferror����ֵ�Զ���0*/
                fprintf(stderr,"Error in reading file %s.\n",file_src);
            if(ferror(fa)!=0)
                fprintf(stderr,"Error in writing file %s.\n",file_app);
            fclose(fs);
            files++;
            printf("File %s appended.\n",file_src);
            puts("Next source file (empty line to quit):");
        }
    }
    printf("Done appending.%d files appended.\n",files);
    rewind(fa);
    printf("%s contents:\n",file_app);
    while((ch=getc(fa))!=EOF)
        putchar(ch);
    fputc('\n',stdout);
    puts("Done displaying.");
    fclose(fa);

    return 0;
}

void append(FILE *source,FILE *dest)                                //��Դ�ļ������ݿ�����Ŀ���ļ�
{
    size_t bytes;
    static char temp[BUFSIZE];

    while((bytes=fread(temp,sizeof(char),BUFSIZE,source))>0)        //��Դ�ļ��ж�ȡ���ݵ�����temp
        fwrite(temp,sizeof(char),bytes,dest);                       //�������е�����д�뵽Ŀ���ļ�����
}

char *s_gets(char *st,int n)
{
    char *ret_val;
    char *find;

    ret_val=fgets(st,n,stdin);                              /*������볤�ȳ�����n����ô�����о�ֻ����ĩβ����һ����ָ��
                                                            �����û�г���������ȱ�Ȼ���ڿ�ָ���ǰ������һ�����з�*/
    if(ret_val)                                             //���if�������Ϊ������������з�
    {
        find=strchr(st,'\n');
        if(find)
            *find='\0';
        else
            while(getchar()!='\n')
                continue;
    }
    return ret_val;
}
