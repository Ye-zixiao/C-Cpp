#ifndef SEQ_NUM_H_INCLUDED
#define SEQ_NUM_H_INCLUDED

using namespace std;/*为什么在头文件中加入这句话之后才能正确运行？？？？？*/

inline bool size_is_ok(int size);                                       //判定索引是否合理
bool seq_elem(int pos,int &elem,const vector<int>* (*seq_ptr)(int));    //返回索引位置的数值
const vector<int> *fibo_seq(int size);                                  //生成Fibonacci数列
const vector<int> *square_seq(int size);                                //生成平方数列

inline bool size_is_ok(int size)                //内联函数必须将定义放到头文件中
{
    if(size<1||size>1024)
    {
        cerr<<"Invalid input size!"<<endl;
        return false;
    }
    else
        return true;
}

#endif // SEQ_NUM_H_INCLUDED
