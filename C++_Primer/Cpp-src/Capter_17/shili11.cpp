#include<iostream>
#include<string>
#include<regex>
using namespace::std;

int main(void)
{
    string str("receipt freind friend theif receive");
    regex re("[[:alpha:]]*[^c]ei[[:alpha:]]*");
    for(sregex_iterator iter(str.begin(),str.end(),re),end_iter;
        iter!=end_iter;++iter){
        cout<<iter->prefix().str()<<' '<<iter->str()<<' '<<iter->suffix().str()<<endl;
    }
    cout<<endl;

    return 0;
}
