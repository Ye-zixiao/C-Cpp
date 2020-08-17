#include<iostream>
#include<string>
#include<tuple>
using namespace::std;

struct Base {
	Base(int val):value(val){}
	virtual ~Base(){}

	virtual int getval(void) const {
		return value;
	}

private:
	int value;
};

struct Derived :Base {
	Derived(int v1,int v2):
		Base(v1),derived_value(v2){}

	int getval(void) const override {
		return derived_value;
	}

private:
	int derived_value;
};

int main(void)
{
	Derived item(1, 2);
	Base* pbase = &item;
	try {
		throw* pbase;/*�׳�����Ȼ��һ��ָ��Derived����������ָ�룬�������ڸ�ָ���
					 ��̬������ָ������ָ�룬��������ֻ���׳�����������еĻ����Ӷ���*/
	}
	catch (const Base& item) {
		cout << item.getval() << endl;
	}

	return 0;
}
