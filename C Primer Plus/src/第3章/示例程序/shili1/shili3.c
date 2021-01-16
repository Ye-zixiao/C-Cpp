/*------当int型这些数据类型溢出时会怎样？--------*/
#include<stdio.h>
int main(void)
{
    int i=2147483647;                   //取值范围：正负2的31次方
                                         /*这里也可以验证在这台电脑上int型数据占用32位*/
    unsigned int j=4294967295;         //取值范围：0~2的32次方

    printf("%d %d %d.\n",i,i+1,i+2);
    printf("%u %u %u.\n",j,j+1,j+2);

    return 0;
}
