#include<stdio.h>
int main(void)
{
    char ch[256];
    int i=-1;

    do
    {
        i++;
        scanf("%c",&ch[i]);
    }
    while(ch[i]!='\n');//��סÿһ�����ű��ʽ��ֵ�����ұ߱��ʽ��ֵ

    for(;i>=0;i--)              //���ּ������������ڴӵ͵��ߣ�����Ȼ��Ӹߵ��ͣ����򣩴�ӡ�������ڵ�6�µĵ�5��
        printf("%c",ch[i]);
    printf("\n");

    return 0;
}
