#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

/*创建了一个函数对象。在调用函数时使用函数对象就等效于使用函数指针。
    函数对象接受数据，若是偶数返回true*/
class even_elem{
public:
    bool operator()(int elem)
    {
        return elem%2?false:true;
    }
};

int main(void)
{
    ofstream even_file("even_file.txt");
    ofstream odd_file("odd_file.txt");
    if(!even_file||!odd_file)
    {
        cerr<<"Error in opening file"<<endl;
        return -1;
    }

    istream_iterator<int> in(cin);                  //将输入流迭代器（首）与标准输入设备绑定
    istream_iterator<int> eof;
    vector<int> temp_vec;

    copy(in,eof,back_inserter(temp_vec));           //将输入流（容器）首到尾的数据拷贝到临时容器vector中
    vector<int>::iterator division=stable_partition(temp_vec.begin(),
        temp_vec.end(),even_elem());                /*partition算法的作用就将按照even_elem函数对象的规则，
                                                    将求值为true的元素放到求值为false元素的前面。stable_partition
                                                    表示算法执行后不会改变原来相对顺序*/

    ostream_iterator<int> even_put(even_file, z"\n");
    ostream_iterator<int> odd_put(odd_file," ");    //将输出流迭代器指向特定的输出流（有点像C中的重定向）

    copy(temp_vec.begin(),division,even_put);       /*由于偶数在前|奇数在后，所以将division前面的复制到偶数文件中，
                                                    奇数输出到奇数文件中*/
    copy(division,temp_vec.end(),odd_put);

    return 0;
}
