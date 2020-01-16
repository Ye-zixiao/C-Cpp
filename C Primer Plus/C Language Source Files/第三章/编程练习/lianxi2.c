/*-----第二题-----*/
//输入一个ASCII码然后输出一个字符
#include<stdio.h>
int main(void)
{
    char a;         /*事实上char型变量在计算机内存
                        当中是以int型存放的，所以把
                        这个char改成int也没关系*/
    scanf("%d",&a);
    printf("\t%c",a);
    return 0;
}
