#include<stdio.h>
void mikado(int bah);

int main(void)
{
    int pooh=2,bah=5;

    printf("In main(), pooh =%d and &pooh =%p \n",pooh,&pooh);      //���Կ��������32λ�Ŀ���̨���ܹ��ܹ��������ڴ��С����4G
    printf("In main(), bah =%d and &bah =%p \n",bah,&bah);          //��2^32λ
    mikado(pooh);

    return 0;
}

void mikado(int bah)
{
    int pooh=10;

    printf("In mikado(),pooh =%d and &pooh =%p\n",pooh,&pooh);
    printf("In mikado(),bah =%d and &bah =%p\n",bah,&bah);

    return;
}
