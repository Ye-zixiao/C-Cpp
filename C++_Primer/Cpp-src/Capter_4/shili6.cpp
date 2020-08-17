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
        bitset<32> bs(Hash(a+i));//将哈希值转换成二进制进行输出
        cout<<bs<<endl;
    }
}

/*上面的程序是用来计算哈希值，里面就用到将指针强制转换成整型值的实例，
而下面的程序演示了将指针值转换成整数值，然后又将整数值转换成指针中的地址
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
	unsigned int store_double_add = reinterpret_cast<unsigned>(&test);//将test变量的地址的值强制赋给无符号整型变量store_double_add
	cout <<"Address:"<< hex << store_double_add << endl;
	double* ptest = reinterpret_cast<double*>(store_double_add);	//将无符号整型变量store_double_add中的值又重新转换回指向double变量test的指针
	cout << *ptest << endl;

	return 0;
}
