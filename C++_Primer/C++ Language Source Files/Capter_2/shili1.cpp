#include<iostream>

int main(void)
{
    int num_1 = 0;
    int num_2 = 0;
    double dou_1 = 0;

    int* pnum_1 = &num_1;
    int* pnum_2 = &num_2;
    double* pdouble = &dou_1;

    std::cout << pnum_1 << std::endl;
    std::cout << pnum_2 << std::endl;//打印指针中的数值可知int在该计算机中占据了4个字节
    std::cout << pdouble << std::endl;
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(double) << std::endl;
    std::cout<<sizeof(long long)<<std::endl;
    std::cout<<sizeof(long double)<<std::endl;

    return 0;
}
