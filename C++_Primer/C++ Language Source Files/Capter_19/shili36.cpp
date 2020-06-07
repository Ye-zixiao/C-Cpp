#include<iostream>
#include<utility>
#include<string>
using namespace::std;

class Test {
	friend ostream& operator<<(ostream& os, const volatile Test& t);
	int value = 0;
public:
	Test(int v):value(v){}
	Test(const volatile Test&t):value(t.value){}
	Test(volatile Test&& t)noexcept :value(std::move(t.value)) { t.value = 0; }
	Test& operator=(const volatile Test& t) {//��ͨ��������ͨ����volatile��������ͨ
		value = t.value;
		return *this;
	}
	volatile Test& operator=(const volatile Test& t) volatile {//volatile������volatile������ͨ������volatile
		value = t.value;
		return *this;
	}
	Test& operator=(volatile Test&& t) noexcept {//volatile��������ͨ��������ͨ��������ͨ
		value = std::move(t.value); t.value = 0;
		return *this;
	}
	volatile Test& operator=(volatile Test&& t) volatile noexcept{//volatile������volatile������ͨ������volatile
		value = std::move(t.value); t.value = 0;
		return *this;
	}
};

ostream& operator<<(ostream& os, const volatile Test& t) {
	return os << t.value;
}

int main(void)
{
	//volatile---->volatile
	volatile Test vitem1(42);
	volatile Test vitem_cpy1 = vitem1, vitem_mv1 = std::move(vitem1);
	cout << vitem1 << ' ' << vitem_cpy1 << ' ' << vitem_mv1 << endl;

	//volatile---->normal
	volatile Test vitem2(53);
	Test vitem_cpy2 = vitem2, vitem_mv2 = std::move(vitem2);
	cout << vitem2 << ' ' << vitem_cpy2 << ' ' << vitem_mv2 << endl;

	//normal----->volatile
	Test item3(523);
	volatile Test vitem_cpy3 = item3, vitem_mv3 = std::move(item3);
	cout << item3 << ' ' << vitem_cpy3 << ' ' << vitem_mv3 << endl;

	//normal----->normal
	Test item4(52);
	Test item_cpy4 = item4, item_mv4 = std::move(item4);
	cout << item4 << ' ' << item_cpy4 << ' ' << item_mv4 << endl;

	return 0;
}
