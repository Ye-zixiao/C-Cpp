#ifndef SEQ_NUM_H_INCLUDED
#define SEQ_NUM_H_INCLUDED

using namespace std;/*Ϊʲô��ͷ�ļ��м�����仰֮�������ȷ���У���������*/

inline bool size_is_ok(int size);                                       //�ж������Ƿ����
bool seq_elem(int pos,int &elem,const vector<int>* (*seq_ptr)(int));    //��������λ�õ���ֵ
const vector<int> *fibo_seq(int size);                                  //����Fibonacci����
const vector<int> *square_seq(int size);                                //����ƽ������

inline bool size_is_ok(int size)                //�����������뽫����ŵ�ͷ�ļ���
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
