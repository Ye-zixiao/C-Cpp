#include<stdio.h>

int main(void)
{
    char ch[256];
    int i=0;

    printf("Enter the inputs:\n");
    do
    {
        scanf("%c",&ch[i]);
    }
    while(ch[i]!='\n',i++);/*������һ�������ʹ�÷������Ƕ��ű��
                                ʽ��ֵ�ǵ����Ҳ���ʽ��ֵ�������ʽ
                                ���scanf����ʱ�ͻ��i++��Ϊwhile����
                                ��ֵ����i++��Ȼ��������*/
                                //���������÷������ʣ��������Ҳ������ȷ�����У�
    for(i--;i>=0;i--)
        printf("%c",ch[i]);
    printf("\n");

    return 0;
}
