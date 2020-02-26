#include<iostream>
using namespace::std;

class Test {
public:
	constexpr Test(int val):cvalue(val){}

	void set_value(int val) { cvalue = val; }
	constexpr int get_cvalue(void) const { return cvalue; }
private:
	int cvalue;
};

int main(void)
{
	Test test(10);
	cout << "(It is not constexpr object)\nbefore:" << test.get_cvalue() << endl;
	test.set_value(12);
	cout << "after:" << test.get_cvalue() << endl << endl;
	//int arr_1[test.get_cvalue()];
	/*虽然定义了一个字面值常量类，但是这不意味着以普通的方式定义字面值常量类类对象就是一个constexpr对象，
	如同int类型（int是字面值类型）一样，如果不加constexpr初始化一个对象，那它显然不会是constexpr对象；但若加了
	constexpr对象，且对象的初始表达式确实符合规矩，是一个常量表达式，那么此时创建的对象就是constexpr对象
	*/

	cout<<"it is constexpr object!"<<endl;
	int value = 10;
	/*constexpr Test vtest(value);*/
	//constexpr使得编译器会特定检查定义的对象的结果是否符合预期，是一个constexpr对象，若不是就会报错，
	//这个和int前加constexpr一样
	//constexpr int vtest(value);//这里也会报错

	constexpr Test ctest(10);
	cout << ctest.get_cvalue() << endl;
	int arr_2[ctest.get_cvalue()];

	return 0;
}
