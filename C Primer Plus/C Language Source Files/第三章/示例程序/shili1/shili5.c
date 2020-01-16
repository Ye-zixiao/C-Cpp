/*-------显示支付带代表的代码编号----------*/
#include<stdio.h>
int main(void)
{
    char ch;

    printf("Please enter a character.\n");
    scanf("%c",&ch);                            /*输入一个字符，%c表示的是要的是一个字符，
                                                而%ch表示将这个输入字符存放在ch这个字符的内存地址中*/
    printf("The code for %c is %d.\n",ch,ch);   //前者显示ch它所代表的字符，而后者表示的是显示出ch所代表字符的ASCII码值

    return 0;
}
