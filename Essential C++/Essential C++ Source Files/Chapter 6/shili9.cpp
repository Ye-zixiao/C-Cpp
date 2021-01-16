#include<iostream>
using namespace std;

template<typename Type=int>					//����Ϊ����ģ���������Ĭ�ϵĲ���ֵ
class Test
{
public:
	Test(Type val)
		:_val(val){}

	void hello(void) const
	{
		cout << "hello"<<" ";
		cout << _val << endl;
	}

protected:
	Type _val;
};

template<typename Type=int>
class Testfor :public Test<Type>
{
public:
	Testfor(Type val)
		:Test<Type>(val){}

	void testhello(void) const
	{
		this->hello();
	}

protected:

};

int main(void)
{
	Testfor<string> test("world");
	test.testhello();

	return 0;
}
