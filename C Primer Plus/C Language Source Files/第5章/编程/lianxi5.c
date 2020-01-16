#include<stdio.h>
int main(void)
{
    int days;
    int money;

    printf("Enter the days you work:\n");
    scanf("%d",&days);
    while(days>0)
    {
        money=0;                                    //对金钱初始化
        while(days>0)                             //用while对所赚的钱进行累加
        {
            money+=days;
            days--;
        }
        printf("You earn the money :%d.\n",money);

        printf("Please keep entering(enter the number<=0 to quit).\n");
        scanf("%d",&days);                          //再次输入天数
    }
    printf("System ends.\n");

    return 0;
}
