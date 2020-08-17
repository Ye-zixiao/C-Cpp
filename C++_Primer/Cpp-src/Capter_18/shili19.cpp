#include<iostream>
#include<string>
using namespace::std;

class Class {};

class Base :public Class {
public:
	Base() = default;
	Base(const Base&) = default;
	//Base(int v):
	//	value(v){}//��Class�������Ĭ�Ϲ��캯��
	//����Ķ�Base(int)Ҳ����д�����µ���ʽ��
	Base(int v):
		Class(),value(v){}//��Ϊ��Щ����Ĳ���ʹ��Ĭ�ϵľͿ����ˣ���Ӱ��ʵ�ʵĳ�ʼ��

private:
	int value;
};

class D1 :public virtual Base {
public:
	D1() = default;
	D1(const D1&) = default;
	D1(int v):Base(v){}
};

class D2 :public virtual Base {
public:
	D2() = default;
	D2(const D2&) = default;
	D2(int v) :Base(v){}
};

class MI :public D1, public D2 {
public:
	MI() = default;
	MI(const MI&) = default;
	MI(int v):
		Base(v),D1(v),D2(v){}
};

class Final :public MI, public Class {
public:
	Final() = default;
	Final(const Final&) = default;
	Final(int v):
		Base(v),MI(v),Class(){}
	//���Class�����ϲ��ӽ�ȥ��ʵҲû�й�ϵ����Ϊ��˳Ӧ�������������������ĳ�ʼ�������캯�����Ĺ��򣬻��Ǽӽ�ȥ��Ƚ���������
};

int main(void) {
	Final item(10);
	return 0;
}
