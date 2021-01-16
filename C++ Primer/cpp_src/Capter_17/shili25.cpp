#include<iostream>
#include<random>
#include<ctime>
#include<cmath>
using namespace::std;

int main(void)
{
    default_random_engine e(time(0));
    uniform_int_distribution<unsigned> uni_for(0,0);
    for(size_t i=0;i<10;++i)
        cout<<uni_for(e)<<endl;

    return 0;
}
