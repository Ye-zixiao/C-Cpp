/*-��8��*/
#include<stdio.h>
#include<string.h>
char *string_in(const char *st1,const char *st2);

int main(void)
{
    if(string_in("haagts","at"))
        puts("find");
    else
        puts("no");

    return 0;

}

char *string_in(const char *st1,const char *st2)
{
    int seek_length;
    int cmp_length=strlen(st2);                 //�ַ�����Ҫ�Ƚϵĳ���
    seek_length=strlen(st1)-cmp_length+1;       //������Ѱ�ĳ���
    int nofind=1;

    while((nofind=strncmp(st1,st2,cmp_length))&&seek_length>0)//��ε���st1��ָ�룬ֱ���ȽϷ��ֵ���ͬ���ַ���
    {                                                           //����0��һ�㣬Ҫע�⣺С����Ҳ���棬��������seek_length��������п��ܽ�����ѭ��
        seek_length--;
        st1++;
    }
    if(nofind)
        return NULL;
    else
        return (char *)st1;//������������������ָ��const��ָ�븳����һ����ָͨ��
}                           //���(char *)����ǿ��ת������ָͨ���
