#include<string>
#include<iostream>
#include<regex>
#include<string>
#include<algorithm>
using namespace::std;

int main(void)
{
    string str("receive freind height receipt theif albeit");
    regex re("[[:alpha:]]*[^c]ei[[:alpha:]]*");
    vector<string> strvec{"height","neighbor","albeit"};
    for(sregex_iterator iter(str.begin(),str.end(),re),end_iter;iter!=end_iter;
        ++iter){
        if(find(strvec.begin(),strvec.end(),iter->str())!=strvec.end())
            continue;
        cout<<iter->str()<<endl;
    }
    return 0;
}
