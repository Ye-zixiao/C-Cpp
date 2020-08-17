#include<iostream>
#include<cstdlib>
using namespace::std;

class Test {
public:
	Test() = default;
	~Test() try{//�ϳɵ��쳣˵���������Ϊ��ϳɵ������������õ��쳣˵��һ��
		throw runtime_error("test");
	}
	catch (runtime_error& err) {
		cerr << err.what() << endl;
	}
};

void func(void) {
	Test item;
	cout << boolalpha << noexcept(item.~Test()) << endl;
}


int main(void)
{
	try {
		func();
	}
	catch (runtime_error& err) {
		cerr << err.what() << endl;
	}

	return 0;
}
