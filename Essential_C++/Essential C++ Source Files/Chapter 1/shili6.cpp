#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
    int value=1024;
    int *pvalue=&value;
    if(*pvalue!=1000)
    {
        cout<<"Value is not equivalent to 1000.\n";
        *pvalue=1000;
        cout<<"Now value is "
            <<*pvalue
            <<".\n";
        cout<<pvalue
            <<".\n";
    }

    return 0;
}
