#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
using namespace std;

int main(void)
{
    int arr[10]={1,3,5,8,5,3,1,5,8,1};
    vector<int> vec(arr,arr+10);
    set<int> iset(vec.begin(),vec.end());
    iset.insert(4);//����set֮����Ȼ�Ǵ�С��������

    set<int>::iterator iter=iset.begin();
    for(;iter!=iset.end();iter++)
        cout<<*iter<<' ';
    cout<<endl;

    return 0;
}
