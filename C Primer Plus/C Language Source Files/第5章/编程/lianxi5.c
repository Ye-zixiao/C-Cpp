#include<stdio.h>
int main(void)
{
    int days;
    int money;

    printf("Enter the days you work:\n");
    scanf("%d",&days);
    while(days>0)
    {
        money=0;                                    //�Խ�Ǯ��ʼ��
        while(days>0)                             //��while����׬��Ǯ�����ۼ�
        {
            money+=days;
            days--;
        }
        printf("You earn the money :%d.\n",money);

        printf("Please keep entering(enter the number<=0 to quit).\n");
        scanf("%d",&days);                          //�ٴ���������
    }
    printf("System ends.\n");

    return 0;
}
