#include<stdio.h>
#include<string.h>
#define SIZE 30
#define BUGSIZE 13
char *s_gets(char *st,int n);

int main(void)
{
    char flower[SIZE];                       //30
    char addon[]="s smell like old shoes.";
    char bug[BUGSIZE];                       //13
    int available;

    puts("What is your favoriate flower?");
    s_gets(flower,SIZE);
    if((strlen(addon)+strlen(flower)+1)<=SIZE)            //addon+��+���ַ��������鳤��
        strcat(flower,addon);
    puts(flower);

    puts("What is your favoriate bug?");
    s_gets(bug,BUGSIZE);                        //13
    available=BUGSIZE-strlen(bug)-1;            //���㻹�����ӵ��ַ���
    strncat(bug,addon,available);
    puts(bug);

    return 0;
}

char *s_gets(char *st,int n)
{
    char *ret_val;
    int i=0;

    ret_val=fgets(st,n,stdin);
    if(ret_val)                                 //��鷵�ص�ָ��char��ָ���Ƿ�Ϊnull
    {
        while(st[i]!='\n'&&st[i]!='\0')       //��һ��������黻�з�����Ϊ�˽���ת��Ϊ���ַ�
            i++;                                //�ڶ���������Ϊ�˼�������ַ�����SIZE�������Ϊ���ǽ����뻺���еĶ����ַ�������
        if(st[i]=='\n')
            st[i]='\0';
        else
            while(getchar()!='\n')
                continue;
    }

    return ret_val;
}
