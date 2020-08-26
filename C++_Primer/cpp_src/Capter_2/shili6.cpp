#include<iostream>

/*
*注意这个程序在code::blocks是不能正常编译通过的
*/

int main(void)
{
    constexpr int value = 10;//value是一个常量表达式
    std::cout << value << std::endl;

    //value = 19l;
    const int* pvalue = &value;//允许一个指向const的指针指向常量表达式value
    constexpr const int* ppvalue = &value;//ppvalue是一个指向const的const指针

    int test_value = 10;
    constexpr int* pppvalue = &test_value;

    std::cout << *pppvalue << std::endl;
    *pppvalue = 99;
    std::cout << *pppvalue << std::endl;

    return 0;
}

