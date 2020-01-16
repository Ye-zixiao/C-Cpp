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
        min=sec/SEC_PER_MIN;                    //对秒整除：得 --分
        left=sec%SEC_PER_MIN;                   //对秒求余：得 --秒
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
    //scanf("%d",&input);                                                             //在进入循环之前要求输入一个数字作为初始值
    while(input>0)
    {
        scanf("%d",&input);
        min=input/SEC_PER_MIN;                                                      //对输入进行整除
        sec=input%SEC_PER_MIN;                                                      //对输入进行求余
        printf("The input number is %d ,and it qual to %d:%d.\n",input,min,sec);
        printf("Go ahead!\n");
       // scanf("%d",&input);                                                         //再一次要求输入一个值，然后再到while那里进行判断
    }
    printf("OK,it is finished!");                                                    //表示退出了循环体，打印出一个结束语

    return 0;
}
/*根据复习题的第5题对上面的程序改动了下*/
