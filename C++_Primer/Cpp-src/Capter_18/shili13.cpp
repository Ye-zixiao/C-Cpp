#include<iostream>

namespace nsp {

	class Test {
		friend void f(void);
		friend void func(const Test&);

	public:
		Test() = default;
	};

	void joker(const Test&);
}

int main(void)
{
	nsp::Test item;
	f();//����f()����û���βΣ����������޷����ݺ����β�ȥ��ʵ���������ڵ������ռ�ȥ������Ӧ�ĺ���
	func(item);//���ں���func()��һ���βΣ����Ա�����������亯��ʵ�ε������ռ�ȥ������Ӧ�ĺ�������

	joker(item);

	return 0;
}
