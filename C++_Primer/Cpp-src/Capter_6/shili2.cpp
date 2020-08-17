#include<iostream>
using namespace::std;

void test(int value)
{
    value=11;
    cout<<value<<endl;
}

void testtest(const int *pvalue)
{
    cout<<*pvalue<<endl;
}

void testtest(int *pvalue)
{
    *pvalue=109;
    cout<<*pvalue<<endl;
}

int main(void)
{
    int value=10;
    const int *cpvalue=&value;
    testtest(cpvalue);
    testtest(&value);
    value=10;
    testtest(const_cast<const int*>(&value));

    return 0;
}
