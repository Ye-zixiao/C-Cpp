#include<iostream>

/*
int main(void)
{
    int sum=0,val=50;
    while(val<=100)
    {
        sum+=val;
        ++val;
    }
    std::cout<<"Sum of 1 to 10 inclusive is "
        <<sum<<std::endl;

    return 0;
}
*/
/*
int main(void)
{
    int sum=0,val=10;
    while(val)
    {
        std::cout<<val<<std::endl;
        sum+=val;
        --val;
    }

    std::cout<<"The sum of these numbers is "
    <<sum<<std::endl;

    return 0;
}
*/

int main(void)
{
    int v1=0,v2=0;
    int sum=0;

    std::cout<<"Please enter two number(first is bigger,last is smaller):";
    std::cin>>v1>>v2;

    while(v1<=v2)
    {
        std::cout<<v1<<std::endl;
        sum+=v1;
        ++v1;
    }

    //std::cout<<"The sum is "<<sum<<"."<<std::endl;

    return 0;
}
