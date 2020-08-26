#include<iostream>

/*
int main(void)
{
    int sum=0;
    for(int val=50;val<=100;++val)
        sum+=val;

    std::cout<<"The sum is "<<sum<<std::endl;

    return 0;
}
*/
/*
int main(void)
{
    for(int val=10;val>=0;--val)
        std::cout<<val<<std::endl;

    return 0;
}
*/

int main(void)
{
    int init_val=0,end_num=0;
    std::cout<<"Please enter two numbers for this program:";
    std::cin>>init_val>>end_num;

    for(;init_val<=end_num;++init_val)
        std::cout<<init_val<<" ";

    return 0;
}
