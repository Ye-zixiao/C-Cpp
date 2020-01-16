#include<stdio.h>
int main(void)
{
    char side_a[]="Side A";         /*要注意编译器储存数据时是自顶向下放置数据，
                                    而puts函数在未读取到空字符时是从低字节读到高字节方向读取的*/
    char dont[]={'A','O','W'};
    char side_b[]="Side B";

    puts(dont);

    return 0;
}
