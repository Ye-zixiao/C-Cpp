/*-------��ʾ֧��������Ĵ�����----------*/
#include<stdio.h>
int main(void)
{
    char ch;

    printf("Please enter a character.\n");
    scanf("%c",&ch);                            /*����һ���ַ���%c��ʾ����Ҫ����һ���ַ���
                                                ��%ch��ʾ����������ַ������ch����ַ����ڴ��ַ��*/
    printf("The code for %c is %d.\n",ch,ch);   //ǰ����ʾch����������ַ��������߱�ʾ������ʾ��ch�������ַ���ASCII��ֵ

    return 0;
}
