#include<iostream>
#include<string>
#include<vector>
using namespace::std;

class Test {
public:
	Test(int value):
		value_3(value++),value_2(value++),value_1(value++){}
	//数据成员初始化顺序与它们在类定义中的出现顺序一致，所以value_1虽然在构造函数初始值列表的末尾，但却是第一个进行初始化的
	vector<int> get_value(void)const { return { value_1,value_2,value_3 }; }

private:
	int value_1 = 0;
	int value_2 = 0;
	int value_3 = 0;
};

int main(void)
{
	Test test(1);
	vector<int>&& ref_value = test.get_value();
	for (const auto& elem : ref_value)
		cout << elem << ' ';
	cout << endl;

	return 0;
}
