#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<functional>
using namespace std;

template<typename InIter,typename OutIter,
            typename ElemType,typename FunObj>
OutIter filter(InIter first,InIter last,OutIter re_out,ElemType &value,
               FunObj pred);

int main(void)
{
    int arr[7]={1,3,4,7,5,4,8};
    vector<int> vec(arr,arr+7);

    vector<int> fil;//һ��Ҫ������ʼ������һ����Χ����Ȼ����ֱ��ʹ��iter++����ʾָ��Խ����ɳ������
                        //ʹ�÷���ָ�븳ֵ��ʹ��push_back�ǲ�һ����
    int value=5;
    //filter(vec.begin(),vec.end(),fil.begin(),value,less<int>());ԭ��
    filter(vec.begin(),vec.end(),back_inserter(fil),value,less<int>());
                                /*ʹ�ò����������Ͳ��ᵣ�Ĳ���ʱ��ָ��ķ���ָ���λ����
                                    Խ���*/
    return 0;
}

template<typename InIter,typename OutIter,
            typename ElemType,typename FunObj>
OutIter filter(InIter first,InIter last,OutIter re_out,ElemType &value,
               FunObj pred)
{
    while((first=find_if(first,last,bind2nd(pred,value)))!=last)
    {
        cout<<"found value: "<<*first<<endl;
        *re_out++=*first++;
    }
    return re_out;
}
