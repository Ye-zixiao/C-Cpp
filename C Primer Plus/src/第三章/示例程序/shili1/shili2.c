/*---------------演示错误的int屏幕打印写法------------*/
#include <stdio.h>
int main(void)
/*{
    int num;
    num=2147483648;
    printf("%d\n",num);//可以推断int型的长度是32位（在这个64位机里）

    return 0;
}*/

/*错误的写法：
{
    int ten=10;
    int two=2;
    printf("%d minus %d=%d.\n",ten);//这种错误的写法会导致系统会随机赋值给后面两个值

    return 0;
}*/


//正确的写法：
{
    int ten=10;
    int two=2;
    printf("%d minus %x=%#x.\n",ten,two,ten-two);/*这里分别用到得了转换说明：%d——表示转换成十进制数；
                                                                                   %o——表示转换成八进制数
                                                                                   %x——表示转换成十六进制数
                                                                                   %#x——表示转换成十六进制数，同时在前面加入0x标识*/
}
