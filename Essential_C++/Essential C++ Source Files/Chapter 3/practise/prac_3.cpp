#include<iostream>
#include<vector>
#include<fstream>
#include<iterator>
#include<algorithm>
using namespace std;

int main(void)
{
    ofstream out_file1("output_odd.txt");       //打开文件
    ofstream out_file2("output_ou.txt");
    if(!out_file1||!out_file2)
    {
        cout<<"Error in opening file"<<endl;
        return -1;
    }

    istream_iterator<int> instad(cin);          //指定输入流迭代器的首尾，并绑定输入流
    istream_iterator<int> eof;

    vector<int> int_arr;
    copy(instad,eof,back_inserter(int_arr));    //将输入流指定范围内的数据复制到int_arr容器当中

    vector<int> odd,ou;
    vector<int>::iterator iter=int_arr.begin(); //将int_arr容器当中的数据分类成奇数和偶数放到不同的容器当中
    for(;iter!=int_arr.end();iter++)
    {
        if(!((*iter)%2))
            ou.push_back(*iter);
        else
            odd.push_back(*iter);
    }

    ostream_iterator<int> os_1(out_file1," ");
    ostream_iterator<int> os_2(out_file2,"\n");

    copy(odd.begin(),odd.end(),os_1);           //将vector容器中的数据吧复制到输出流容器当中
    copy(ou.begin(),ou.end(),os_2);         /*流迭代器的理解要点是：
                                                将输入输出流视为容器！*/

    return 0;
}
