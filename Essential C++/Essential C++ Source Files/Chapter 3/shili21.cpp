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

    vector<int> fil;//一定要给它初始化设置一个范围，不然后面直接使用iter++会提示指针越界造成程序崩溃
                        //使用泛型指针赋值和使用push_back是不一样的
    int value=5;
    //filter(vec.begin(),vec.end(),fil.begin(),value,less<int>());原版
    filter(vec.begin(),vec.end(),back_inserter(fil),value,less<int>());
                                /*使用插入适配器就不会担心插入时所指向的泛型指针的位置是
                                    越界的*/
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
