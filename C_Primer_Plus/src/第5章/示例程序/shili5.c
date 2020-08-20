/*-----计算小麦的数量-----*/
#include<stdio.h>
#define SQUARES 64
int main(void)
{
    const double CROP=2E16;                                 //世界小麦产量
    double current,total;
    int count=1;

    printf("square     grains       total     \
fraction of \n");                                            //其实就是拼接两个句子罢了
    printf("           added        grains    \
world total\n");
    total=current=1.0;
    printf("%4d %13.2e %12.2e %12.2e\n",count,current,
           total,total/CROP);                                //打印出第一行小麦的数量
    while(count<SQUARES)                                      //刚进去的时候会检验count（=1）是否小于64
    {
        count++;
        current=current*2.0;
        total+=current;
        printf("%4d %13.2e %12.2e %12.2e\n",count,current,
               total,total/CROP);
    }

    return 0;
}
