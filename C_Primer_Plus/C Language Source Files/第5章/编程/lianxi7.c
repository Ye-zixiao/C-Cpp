/*-----设计带参函数？？？----*/
#include<stdio.h>
float cubed(float n);
int main(void)
{
    float num_input,result;
    int rv;

    printf("Please enter the number you want:\n");
    rv=scanf("%f",&num_input);
    while(rv==1)                        //判断输入的数是否大于0，若大于0进入while循环计算立方值
    {
        result=cubed(num_input);
        printf("The number you input:%0.2f ,and \
it's cubed is %0.3f.\n",num_input,result);
        printf("Keep entering(enter the number<=0 to quit this system).\n");
        rv=0;                           //重新置位rv是为了保险起见，防止第一次rv=1后第二次不返回1但是没有改写rv的值
        rv=scanf("%f",&num_input);
    }
    printf("System ends.\n");

    return 0;
}

float cubed(float n)                    /*使用返回值的带参函数计算输入数的立方，
                                            如果不用返回值，根据题意可以把打印平
                                            方值这一步放到调用的函数中间*/
{
    float cubed;
    cubed=n*n*n;

    return cubed;
}
