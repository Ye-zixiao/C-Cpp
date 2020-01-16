#include<iostream>
#include<vector>
#include<fstream>
#include<iterator>
#include<algorithm>
using namespace std;

int main(void)
{
    ofstream out_file1("output_odd.txt");       //���ļ�
    ofstream out_file2("output_ou.txt");
    if(!out_file1||!out_file2)
    {
        cout<<"Error in opening file"<<endl;
        return -1;
    }

    istream_iterator<int> instad(cin);          //ָ������������������β������������
    istream_iterator<int> eof;

    vector<int> int_arr;
    copy(instad,eof,back_inserter(int_arr));    //��������ָ����Χ�ڵ����ݸ��Ƶ�int_arr��������

    vector<int> odd,ou;
    vector<int>::iterator iter=int_arr.begin(); //��int_arr�������е����ݷ����������ż���ŵ���ͬ����������
    for(;iter!=int_arr.end();iter++)
    {
        if(!((*iter)%2))
            ou.push_back(*iter);
        else
            odd.push_back(*iter);
    }

    ostream_iterator<int> os_1(out_file1," ");
    ostream_iterator<int> os_2(out_file2,"\n");

    copy(odd.begin(),odd.end(),os_1);           //��vector�����е����ݰɸ��Ƶ��������������
    copy(ou.begin(),ou.end(),os_2);         /*�������������Ҫ���ǣ�
                                                �������������Ϊ������*/

    return 0;
}
