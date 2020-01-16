#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#define STOP '|'
int main(void)
{
    char c;
    char prev;
    long n_chars=0L;
    int n_words=0;
    int n_lines=0;
    int p_lines=0;
    bool inword=false;

    printf("Enter text to analysis(| to quit this program).\n");
    prev='\n';

    while((c=getchar())!=STOP)
    {
        n_chars++;
        if(c=='\n')
            n_lines++;
        if(!isspace(c)&&!inword)//��������ַ����ǿհ��ַ��ҵ��ʱ�ǻ���0����ô����ǵ��ʵĿ�ʼ
        {
            inword=true;        //�õ��ʱ��λΪ1
            n_words++;
        }
        if(isspace(c)&&inword)  //���������ַ��ǿհ��ַ����ҵ��ʱ��λ��1����ô���ǵ��ʵĽ���
            inword=false;       //�õ���λΪ0
        prev=c;                 //Ϊ���Ǽ�¼�˳�֮ǰ���ַ������Ƿ��ǡ�\n�����з�
    }

    if(prev!='\n')//��¼������
        p_lines=1;
    printf("characters=%ld, words=%d,lines=%d,",
           n_chars,n_words,n_lines);
    printf("partial line=%d\n",p_lines);

    return 0;
}
