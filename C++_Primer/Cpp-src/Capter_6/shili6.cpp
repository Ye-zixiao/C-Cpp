#include<iostream>
#include<string>
using namespace::std;

int main(int argc,char *argv[])
{
    if(argc<5)
        cerr<<"parameter is not enough"<<endl;
    else
    {
        for(size_t i=0;i!=argc;++i)
            cout<<string(argv[i])<<' ';
        cout<<endl;
    }

    return 0;
}
