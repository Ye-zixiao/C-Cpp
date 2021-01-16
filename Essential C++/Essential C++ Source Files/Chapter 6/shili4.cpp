#include<iostream>
#include<string>
#include<vector>
using namespace std;

template<typename elemType>
class less_than
{
public:
    less_than(const elemType& val)
        :_val(val){}

    bool operator()(const elemType& val)
    {
        return val<_val;
    }
    void val(const elemType& newval){_val=newval;}
    elemType val(){return _val;}

private:
    elemType _val;
};

int main(void)
{
    less_than<int> lti(21);

    if(lti(10))
        cout<<"It is less than "<<lti.val()<<endl;

    return 0;
}
