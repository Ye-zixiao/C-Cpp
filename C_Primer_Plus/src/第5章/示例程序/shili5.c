/*-----����С�������-----*/
#include<stdio.h>
#define SQUARES 64
int main(void)
{
    const double CROP=2E16;                                 //����С�����
    double current,total;
    int count=1;

    printf("square     grains       total     \
fraction of \n");                                            //��ʵ����ƴ���������Ӱ���
    printf("           added        grains    \
world total\n");
    total=current=1.0;
    printf("%4d %13.2e %12.2e %12.2e\n",count,current,
           total,total/CROP);                                //��ӡ����һ��С�������
    while(count<SQUARES)                                      //�ս�ȥ��ʱ������count��=1���Ƿ�С��64
    {
        count++;
        current=current*2.0;
        total+=current;
        printf("%4d %13.2e %12.2e %12.2e\n",count,current,
               total,total/CROP);
    }

    return 0;
}
