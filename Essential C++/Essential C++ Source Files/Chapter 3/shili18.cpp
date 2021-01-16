//=============模板函数-复制排序后砍掉后面比较大的===========//
#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

template<typename InIter,typename OutIter,typename ElemType,typename Comp>
void filter(InIter first, InIter last, OutIter re_back, ElemType value, Comp pred);

template<typename InIter>
void display(InIter first, InIter last);

int main(void)
{


	return 0;
}

template<typename InIter, typename OutIter, typename ElemType, typename Comp>
void filter(InIter first, InIter last, OutIter re_back, ElemType value, Comp pred)
{

}
