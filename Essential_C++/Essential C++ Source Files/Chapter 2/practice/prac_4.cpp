#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

template<typename elemType>
inline elemType max(elemType x,elemType y);

template<typename elemType>
inline elemType max(const vector<elemType> &x);

int main(void)
{
    cout<<::max(1.2,3.4)<<endl;// "::"��ʾ�����Լ�д�ĺ�����������std�еĺ������г�ͻ
    cout<<::max('x','m')<<endl;
    cout<<::max(3,5)<<endl;
    cout<<::max("string","hello")<<endl;

    float arr[4]={1.2,3.4,6.8,1.3};
    const vector<float> vec_arr(arr,arr+4);
    float max_num=max(vec_arr);
    cout<<max_num<<endl;

    return 0;
}

template<typename elemType>
inline elemType max(elemType x,elemType y)
{
    return x>y?x:y;
}

template<typename elemType>
inline elemType max(const vector<elemType> &x)
{
    return *max_element(x.begin(),x.end());//�����㷨����ͷ��β�ҳ����Ԫ��
}
