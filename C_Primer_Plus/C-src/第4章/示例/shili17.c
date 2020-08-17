/*-----演示抑制赋值修饰符在scanf函数中的使用的方法----*/
#include<stdio.h>
int main(void)
{
    int n;

    printf("Please enter three integers:\n");
    scanf("%*d %*d %d",&n);
    printf("The last integer was %d\n",n);

    return 0;
}
