#include<iostream>
#include<vector>
#include<string>
#include"Stack.h"

int main(void)
{
    Stack st;
    string str;

    while(cin>>str&&!st.full())
        st.push(str);

    if(st.empty())
    {
        cout<<'\n'<<"Oops: no strings were read--bailing out"<<endl;
        return 0;
    }
    else
    {
        st.peek(str);//输入了一个空字符
        if(st.size()==1&&str.empty())
        {
            cout<<'\n'<<"Oops"<<endl;
            return 0;
        }
        cout<<'\n'<<"Read in "<<st.size()<<" strings!"<<endl;
        cout<<"as following:"<<endl;
        while(st.size())
            if(st.pop(str))
                cout<<str<<' ';
        cout<<endl;

    }

    return 0;
}
