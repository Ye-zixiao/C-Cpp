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
    //��ʾ
    for(i=1;i<=QUANLITY;i++)
    {
        printf("%3d",ptd[i-1]);
        if(i%RANGE==0)
            putchar('\n');
    }
    putchar('\n');
    //����
    int top,seek;
    int temp;
    for(top=0;top<QUANLITY-1;top++)
        for(seek=top+1;seek<QUANLITY;seek++)
            if(ptd[top]<ptd[seek])              //�ҳ�����һ�ε����ֵ���ŵ�ptd[top]��λ��
                {
                    temp=ptd[top];
                    ptd[top]=ptd[seek];
                    ptd[seek]=temp;
                }
    //��ʾ����������
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
