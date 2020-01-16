#include<iostream>
/*
int main(void)
{
    constexpr int value=10;
    //const int *const pvalue=&value;
    //constexpr const int *pvalue=&value;这里会被认为是&value不是常量表达式，
    //但是在vs总是可以的，不过也会提示错误但可以编译运行
    constexpr const int* pvalue=nullptr;

    return 0;
}
*/

int value=10;

int main(void)
{
    //constexpr const int *pvalue=&value;此时将value放到函数体外面是可以运行的
    constexpr int *pvalue=&value;

    std::cout<<*pvalue<<std::endl;
    *pvalue=199;
    std::cout<<*pvalue<<std::endl;

    return 0;
}
