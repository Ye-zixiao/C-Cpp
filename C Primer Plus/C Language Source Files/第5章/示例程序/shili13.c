/*-------���ܣ�����ѭ�����������Խ���ǰn���ۼ�---------*/
#include<stdio.h>
int main(void)
{
    int count,num,sum;
    count=0;
    num=0;

    printf("Enter the number \"sum\"\n");
    scanf("%d",&sum);                               //��ʼ����������n����ʾ��ǰ����ĺͣ�
    while(sum>0)                                    //�жϣ�n�Ƿ����0�����С�ڵ���0���ͱ�ʾ�������
    {
        /*����count++��ʾ���ж���䣬Ȼ�����Լ�*/
        while(count++<sum)                         //��while�����ǰn���
            num+=count;
        printf("num=%d.\n",num);                   //��ӡ���

        count=0;                                    //��������λ��ԭ�������֣��Ա���������
        num=0;
        printf("Keep input number\"sum\"\n");
        scanf("%d",&sum);
    }
    printf("Done.\n");

    return 0;
}
