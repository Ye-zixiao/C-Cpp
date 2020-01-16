/*----------演示如何打印long、short、unsigned long这些数据类型---------*/
int main(void)
{
    unsigned int un=3000000000;
    short end=200;
    long big=65537;
    long long verybig=12345678908642;
                                                              //以下全是只讲整数的情况
    printf("un=%u and not %d.\n",un,un);                    //int的最大值 小于 unsigned int的最大值，所以当uint（3000000000）表示成int时会溢出
    printf("end=%hd and not %d.\n",end,end);                /*int的最大值 大于 short的最大值，所以没有溢出*/
    printf("big=%ld and not %hd.\n",big,big);               //short的最大值 小于 long的最大值，所以long（65537）表示成short时溢出
    printf("verybig=%lld and not %ld.\n",verybig,verybig);  //long的最大值 效于 long long的最大值，所以long long（12345678908642）表示成long时会溢出

    return 0;
}
/*
在这台计算机上：
long long-------64位；
long -----------32位；
int-------------32位；
short-----------16位。
*/
