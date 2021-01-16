#include<iostream>
#include<cctype>
#include<string>
using namespace::std;

int main(void)
{
    string temp,final_str;
    cout<<"Enter a string for this program:";
    if(getline(cin,temp))
    {
        for(auto c:temp)
            if(!ispunct(c))
                final_str+=c;
        cout<<final_str<<endl;

        return 0;
    }
    else
    {
        cerr<<"No data?"<<endl;
        return -1;
    }
}
