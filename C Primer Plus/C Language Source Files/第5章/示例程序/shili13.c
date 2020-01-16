/*-------功能：可以循环输入数字以进行前n项累加---------*/
#include<stdio.h>
int main(void)
{
    int count,num,sum;
    count=0;
    num=0;

    printf("Enter the number \"sum\"\n");
    scanf("%d",&sum);                               //初始化输入数字n（表示求前几项的和）
    while(sum>0)                                    //判断：n是否大于0，如果小于等于0，就表示程序结束
    {
        /*其中count++表示先判断语句，然后再自加*/
        while(count++<sum)                         //用while语句求前n项和
            num+=count;
        printf("num=%d.\n",num);                   //打印输出

        count=0;                                    //将数字置位回原来的数字，以备重新输入
        num=0;
        printf("Keep input number\"sum\"\n");
        scanf("%d",&sum);
    }
    printf("Done.\n");

    return 0;
}
