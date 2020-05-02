#include<iostream>
#include<string>
#include<utility>
using namespace::std;

class Base {//����Base�ǲ����ƶ���
public:
	Base() = default;

	Base(const Base& item) {
		cout << "Base(const &)" << endl;
	}
	//Base(Base&& item) noexcept{
	//	cout << "Base(Base&&)noexcept" << endl;
	//}

	virtual ~Base() {
		cout << "~Base()" << endl;
	}

};

class Derived :public Base {
public:
	Derived() = default;

	Derived(Derived&&) = default;
	//����������Ϊ�����ϳ��ƶ���������������ǣ������ᱻɾ��������Ȼ�ƶ����캯�����ɺϳɣ����ǿ������캯���ǿ��Ժϳɵ�

	~Derived() {
		cout << "~Derived()" << endl;
	}
};

class withBase {
public:
	withBase() = default;
	withBase(withBase&&) = default;
	~withBase() {}

private:
	Base base;
};

int main(void)
{
	Derived item;
	Derived item_mv = std::move(item);

	cout << "-----------------------------------" << endl;
	withBase test;
	withBase test_mv = std::move(test);

	return 0;
}
