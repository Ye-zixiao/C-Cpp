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
	int&& right = 32;//��ͨ��ֵ����
	const int&& cright = 33;//��const����ֵ����
	int value = 22;
	int& left = value;//��ͨ��ֵ����
	const int& cleft = value;//��const����ֵ����

	f(left);
	f(cleft);
	f(right);
	f(cright);

	f(retleft());
	f(retright());

	ff(retleft());/*ͬ*/ ff(right);
	//ff(retright());
	int& jj = right;


	return 0;
}
