#include <iostream>
#include<bitset>

// Returns a hash code based on an address
unsigned short Hash( void *p ) {
    unsigned int val = reinterpret_cast<unsigned int>( p );
    return ( unsigned short )( val ^ (val >> 16));
}

using namespace std;
int main() {
    int a[20];
    for ( int i = 0; i < 20; i++ )
    {
        bitset<32> bs(Hash(a+i));//����ϣֵת���ɶ����ƽ������
        cout<<bs<<endl;
    }
}

/*����ĳ��������������ϣֵ��������õ���ָ��ǿ��ת��������ֵ��ʵ����
������ĳ�����ʾ�˽�ָ��ֵת��������ֵ��Ȼ���ֽ�����ֵת����ָ���еĵ�ַ
*/
#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

int main(void)
{
	double test = 10.22;
	unsigned int store_double_add = reinterpret_cast<unsigned>(&test);//��test�����ĵ�ַ��ֵǿ�Ƹ����޷������ͱ���store_double_add
	cout <<"Address:"<< hex << store_double_add << endl;
	double* ptest = reinterpret_cast<double*>(store_double_add);	//���޷������ͱ���store_double_add�е�ֵ������ת����ָ��double����test��ָ��
	cout << *ptest << endl;

	return 0;
}
