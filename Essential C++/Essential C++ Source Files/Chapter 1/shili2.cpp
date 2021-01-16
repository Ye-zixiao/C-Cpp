#include<iostream>
#include<string>
using namespace std;

int main(void)
{
    int tries(0);
    cout<<"Are you ready for try "
        //<<++tries
        <<tries++
        <<".\n";

    cout<<"Now the tries is equial to ";
    cout<<tries;
    cout<<'\n';

    bool usr_more=true;
    char usr_rsp;
    cin>>usr_rsp;
    if(usr_rsp=='N')
        usr_more=false;
    else if(usr_rsp=='n')
        usr_more=false;

    if (usr_more==false)
        cout<<"fuck.\n";

    return 0;
}
