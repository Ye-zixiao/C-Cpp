#include<iostream>
#include<string>
using namespace::std;

template<typename T>
void infuc(T&& rvalue) {
	++rvalue;
}

template<typename T>
void func(T&& rvalue) {
	cout << rvalue << endl;/**/
	cout << rvalue << endl;
}


int main(void)
{
    func(23);
}
