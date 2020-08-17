#include<iostream>
#include<memory>
#include<string>
using namespace::std;

class Test {
public:
	Test() = default;
	Test(int val):
		pvalue(make_shared<int>(val)){}

	int get(void) const { return *pvalue; }
	Test& operator=(const Test& item) {
		pvalue = item.pvalue;
		return *this;
	}
	Test& operator=(int val) {
		*pvalue = val;
		return *this;
	}

private:
	shared_ptr<int> pvalue;//Ĭ�ϲ���������ֻ��һ����ָ��
};

int main(void)
{
	Test first;
	{
		Test second(12);
		first = second;
		second = 32;
	}
	cout << first.get() << endl;

	return 0;
}
