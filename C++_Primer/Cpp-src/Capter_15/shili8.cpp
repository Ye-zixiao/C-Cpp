#include<iostream>
using namespace::std;

class Base {
public:
	virtual ~Base() {
		cout << "~Base()" << endl;
	}
};

class nov_Base {
public:
	~nov_Base() {
		cout << "~nov_Base()" << endl;
	}
};

class Derived :public Base {
public:
	~Derived() {
		cout << "~Derived()" << endl;
	}
};

class nov_Derived :public nov_Base {
public:
	~nov_Derived() {
		cout << "nov_Derived()" << endl;
	}
};

int main(void)
{
	Base* pbase = new Derived();
	delete pbase;
	//����Derived�Ļ������������������������������ָ��base��ָ���������ָ��Ķ���Ķ�̬���͵��ö�Ӧ�汾����������
	//�����������������ִ�����Լ������������󣬻��Զ��ص��û���������������ͷ��������еĻ������

	nov_Base* pnovbase = new nov_Derived();
	delete pnovbase;
	//����nov_Derived�Ļ��������������������������������delete���ָ���ʱ��ֻ�ܸ���ָ��ľ�̬���͵��û���汾���������������������������������

	return 0;
}
