#include<stdio.h>
#define SEC_PER_MIN 60
int main(void)
/*{
    int sec,min,left;

    printf("Convert seconds to minutes and seconds!\n");
    printf("Enter the number of seconds (<=0 to quit):\n");
    scanf("%d",&sec);
    while(sec>0)
    {
        min=sec/SEC_PER_MIN;                    //������������ --��
        left=sec%SEC_PER_MIN;                   //�������ࣺ�� --��
        printf("%d seconds is %d minutes,%d seconds.\n",sec,min,left);
        printf("Enter next value (<=0 to quit):\n");
        scanf("%d",&sec);
    }
    printf("Done!");

    return 0;
}*/

{
    int input,min,sec;

    printf("Enter the number of seconds:(if you inputs a number(<=0),\
then quit this system.)\n");
    //scanf("%d",&input);                                                             //�ڽ���ѭ��֮ǰҪ������һ��������Ϊ��ʼֵ
    while(input>0)
    {
        scanf("%d",&input);
        min=input/SEC_PER_MIN;                                                      //�������������
        sec=input%SEC_PER_MIN;                                                      //�������������
        printf("The input number is %d ,and it qual to %d:%d.\n",input,min,sec);
        printf("Go ahead!\n");
       // scanf("%d",&input);                                                         //��һ��Ҫ������һ��ֵ��Ȼ���ٵ�while��������ж�
    }
    printf("OK,it is finished!");                                                    //��ʾ�˳���ѭ���壬��ӡ��һ��������

    return 0;
}
/*���ݸ�ϰ��ĵ�5�������ĳ���Ķ�����*/
