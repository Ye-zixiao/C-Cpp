#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<typename elemType>
void show_msg(const string &msg,vector<elemType> &vec);     //ģ�庯�������Զ��������vector��������ƥ��

template<typename elemType>
void show_msg(elemType value);                          //����ģ��+��������

int main(void)
{
    const string msg="The following is the important message:";
    int arr[8]={1,2,3,4,5,6,7,8,};
    vector<int> vec(arr,arr+8);
    vector<string> st_list;
    st_list.push_back("Hello world!");
    st_list.push_back("Fuck you!");

    show_msg(msg,vec);
    cout<<endl;
    show_msg(msg,st_list);

    show_msg(12.3);
    show_msg("Helloc malloc");

    return 0;
}

template<typename elemType>
void show_msg(const string &msg,vector<elemType> &vec)
{
    cout<<msg<<endl;
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]
            <<((i+1)%2?" ":"\n");
    }
    cout<<endl;
}

template<typename elemType>
void show_msg(elemType value)
{
    cout<<value<<endl;
}
