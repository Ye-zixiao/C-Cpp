#include<iostream>
/*
int main(void)
{
    unsigned u=10;
    int i=-42;

    std::cout<<i+i<<std::endl;
    std::cout<<i+u<<std::endl;

    return 0;
}
*/

int main(void)
{
    unsigned u1=42,u2=10;
    std::cout<<u1-u2<<std::endl;
    std::cout<<u2-u1<<std::endl;
    std::cout<<sizeof(unsigned int)<<std::endl;

    int a=-1;
    unsigned b=1;
    std::cout<<a*b<<std::endl;

    return 0;
}
