/*------һЩ��ƥ�������ת��----*/
#include<stdio.h>
#define PAGES 336
#define WORDS 65618
int main(void)
{
    short num=PAGES;
    short mnum=-PAGES;

    printf("num as short and unsigned short: %hd %hu\n",num,num);
    printf("-num as short and unsigned short: %hd %hu\n",mnum,mnum);//��һ��������ڶ����������Ͳ�ƥ��
    printf("num as int and char:%d %c\n",num,num);//��һ�����������ǵڶ��������ת�����ַ�
    printf("WORDS as int ,short,and char:%d %hd %c\n",WORDS,WORDS,WORDS);//��һ���������ڶ�������������������ת�����ַ�

    return 0;
}
