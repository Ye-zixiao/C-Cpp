#include<stdio.h>
void mikado(int bah);

int main(void)
{
    int pooh=2,bah=5;

    printf("In main(), pooh =%d and &pooh =%p \n",pooh,&pooh);      //可以看出在这个32位的控制台上总共能够给出的内存大小就是4G
    printf("In main(), bah =%d and &bah =%p \n",bah,&bah);          //即2^32位
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
