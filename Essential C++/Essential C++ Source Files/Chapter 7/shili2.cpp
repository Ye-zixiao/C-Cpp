#include<iostream>
#include<string>
using namespace std;

class test
{
public:
    test(int index,int max)
    {
        if(index>max)
            throw "Error";
        else
            cout<<"ok"<<endl;
    }

private:

};

int main(void)
{
    try
    {
       test ts(12,11);
    }
    catch(const char *str)
    {
        cout<<str<<endl;
    }

    return 0;
}
