#include<iostream>
#include<string>
#include<fstream>
using namespace::std;

int main(void)
{
    fstream out("outfile.txt",fstream::out|fstream::in|fstream::ate);
    if(out)
    {
        out<<"hello world3"<<endl;
        out.close();
    }
    else
        cerr<<"Error"<<endl;

    return 0;
}
