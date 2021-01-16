#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
//#include<>
using namespace::std;

template<typename Type>
ostream& operator<<(ostream& os, const vector<Type>& tvec)
{
	for (auto iter = tvec.begin(); iter != tvec.end(); ++iter)
		os << *iter << ' ';
	return os;
}

int main(void)
{
	vector<int> ivec(10);
	for (decltype(ivec)::size_type i = 0; i < ivec.size(); ++i)
		ivec[i] = i;
	cout << ivec << endl;

	decltype(ivec)::size_type i = 0;
	for (auto f = [&] {++i; }; i < ivec.size(); f())
		cout << ivec[i] << ' ';
	cout << endl;


	int value = 10;
	auto f = [value]()mutable {return ++value; };
	/*lambda函数体不仅定义了一个函数体，还定义了一个未命名的类类型。在默认情况下，捕获列表中捕获的变量名字会成为
	该未命名类内的数据成员，（以下是我认为：）但是相对于该未命名类，lambda所定义的函数可以认为相当于普通类中的const
	成员函数，在lambda函数实际执行过程中是不能改变这个数据成员的值。
		但是，当在参数列表后面加上mutable关键字可以使得该未命名类的数据成员（例如当前的value）变成一个mutable数据成员，
	这样即使是lambda函数（const成员函数）执行时也可以改变该数据成员。
		然而，改变类内的mutable数据成员value不代表原来未命名类lambda所捕获的局部变量value能够被lambda函数体改变，因为
	变量是被值捕获的，所以类内的value与类外的局部变量value是两个不同的对象！*/
	cout << f() << endl;
	cout << f() << endl;//改变的是未命名类类内的数据成员value
	cout << value << endl;//但原来的局部对象value没有被改变

	return 0;
}
