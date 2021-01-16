#include<iostream>
#include<vector>
#include<list>
using namespace::std;

int main(void)
{
    list<int> ilist{1,2,3,4,5,56,32};
    vector<double> dvec(ilist.cbegin(),ilist.cend());
    for(const auto &d:dvec)
        cout<<d<<' ';
    cout<<endl;

    vector<int> ivec{1,2,3,4,5,6,2,3,4};
    vector<double> dvec_2(ivec.cbegin(),ivec.cend());
    for(const auto &d:dvec_2)
        cout<<d<<' ';
    cout<<endl;

    return 0;
}
