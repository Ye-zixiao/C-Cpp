#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace::std;

void func(const string&infilename,const string&outevenfile,const string&outoddfile)
{
    ifstream in_file(infilename,ifstream::in);
    ofstream even_file(outevenfile,ofstream::out),odd_file(outoddfile,ofstream::out);
    if(!in_file&&!even_file&&!odd_file)
    {
        cerr<<"can't open this file"<<endl;
        return;
    }

    istream_iterator<int> in_iter(in_file),eof;
    ostream_iterator<int> odd(odd_file,"\n"),even(even_file,"\n");
    for_each(in_iter,eof,[odd,even](int value)mutable{*(value&0x1?odd:even)++=value;});//�������ǲ��ܿ�����ֵ�ģ������������ǿ��Կ�����ֵ��
    //for_each(in_iter,eof,[&odd,&even](int value){(value%2)?(odd=value):(even=value);});��ȷ
    //for_each(in_iter,eof,[odd,even](int value){(value%2)?(odd=value):(even=value);});����
    //��Ϊodd��even�ᱻ�����б�ֵ���񣬲�����lambdaδ������������Ĭ��const���ݳ�Ա����Ȼ���ǲ���
    //��һ��const ostream_iteratorд�����ݣ�Ψһ�ķ��������ڲ����б�������mutable�ؼ���

    //��ʹ������������ʱ�򣬱�����һ�ֽ����ñ�ʾ��ȡ��������ָ���������++��ʾ�����һ��������ϰ�߻����
    //����Ȼ��ʵ�����﷨������out=�ķ�ʽ������ϣ����ʹ��*out++=value�ķ�ʽ��
}

int main(void)
{
	func("in_file.txt", "out_even.txt", "out_odd.txt");
	return 0;
}
