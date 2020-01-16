/*-----可移植整数类型名--------*/
#include<stdio.h>
#include<inttypes.h>
int main(void)
{
    int32_t me32;

    me32=45933945;
    printf("First ,assume int32_t is int: ");
    printf("me32=%d\n",me32);
    printf("Next, let's not make any assumptions.\n");
    printf("Instead,use a\"macro\"from inttypes.h: ");
    printf("me32=%"PRId32"\n",me32);                    /*在C99和C11中使用“PRId32”，
                                                为的是确保int整型在不同系统当中（因为它既可以是32位，也可以是16位）
                                                在输出打印的时候都能显示成为32位的数值。
                                                比方说：
                                                    在int为32位的机子上，显示这个32位的数字需要用到%d；
                                                    但是在int为16位的机子上我们不得不去使用%ld去打印。
                                                为了避免这种麻烦我们使用PRId32来解决                       */

    return 0;
}
