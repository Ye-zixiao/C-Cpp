#include<iostream>

int main(void)
{
    int small_num=0,big_num=0;
    std::cout<<"Please enter two numbers:";
    std::cin>>small_num>>big_num;
    if(small_num<=big_num)
    {
        for(;small_num<=big_num;++small_num)
            std::cout<<small_num<<" ";
    }
    else
        std::cout<<"Something error happened!"<<std::endl;

    return 0;
}
