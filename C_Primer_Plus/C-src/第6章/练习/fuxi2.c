#include<stdio.h>
int main(void)
/*{
    int i,j;
    const char DOL='$';
    const int HANG=4;   //行数
    const int LIE=8;    //列数

    for(i=1;i<=HANG;i++)
    {
        for(j=1;j<=LIE;j++)
            printf("%c",DOL);//傻逼！！！！！直接打印￥当字符串不就行了
        printf("\n");
    }

    return 0;
}*/

{
    int i;
    char ch;

    for(i=0,ch='A';i<4;i++,ch+=2*i)/*逗号运算符中的逗号都是一个序列点，
                                        所以在ch+=2*i运行之前i++已经完成
                                        操作，所以第一次进入循环体时i已经自加成为1*/
        printf("%c",ch);
    return 0;
}
