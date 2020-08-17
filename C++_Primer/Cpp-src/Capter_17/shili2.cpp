#include<iostream>
using namespace::std;

template<typename T>
void f(T&&v){}

template<typename T>
void ff(T&v){}

int& retleft(void);
int&& retright(void);

int main(void)
{
	int&& right = 32;//普通右值引用
	const int&& cright = 33;//对const的右值引用
	int value = 22;
	int& left = value;//普通左值引用
	const int& cleft = value;//对const的左值引用

	f(left);
	f(cleft);
	f(right);
	f(cright);

	f(retleft());
	f(retright());

	ff(retleft());/*同*/ ff(right);
	//ff(retright());
	int& jj = right;


	return 0;
}
