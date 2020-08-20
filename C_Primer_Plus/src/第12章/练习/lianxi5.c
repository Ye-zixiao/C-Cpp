#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define uint unsigned int
#define QUANLITY 100
#define RANGE 10
int rand_num(int num);

int main(void)
{
    int *ptd;
    int i;
    ptd=(int *)malloc(QUANLITY*sizeof(int));
    srand((uint)time(0));
    for(i=0;i<QUANLITY;i++)
        ptd[i]=rand_num(RANGE);
    printf("ptd[99]=%d\n",ptd[99]);
    //显示
    for(i=1;i<=QUANLITY;i++)
    {
        printf("%3d",ptd[i-1]);
        if(i%RANGE==0)
            putchar('\n');
    }
    putchar('\n');
    //排序
    int top,seek;
    int temp;
    for(top=0;top<QUANLITY-1;top++)
        for(seek=top+1;seek<QUANLITY;seek++)
            if(ptd[top]<ptd[seek])              //找出遍历一次的最大值，放到ptd[top]的位置
                {
                    temp=ptd[top];
                    ptd[top]=ptd[seek];
                    ptd[seek]=temp;
                }
    //显示排序后的数字
    for(i=1;i<=QUANLITY;i++)
    {
        printf("%3d",ptd[i-1]);
        if(i%RANGE==0)
            putchar('\n');
    }
    printf("Done.\n");
    free(ptd);

    return 0;

}

int rand_num(int num)
{
    int rand_number;
    rand_number=rand()%num+1;

    return rand_number;
}
