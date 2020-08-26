#include<iostream>
#include<map>
#include<string>
#include<set>
#include<utility>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace::std;

class Test {
	friend bool tcompare(const Test&, const Test&);
	friend ostream& operator<<(ostream& os, const Test& item);
public:
	explicit Test(int val):value(val){}

private:
	int value;
};

bool tcompare(const Test& lhs, const Test& rhs)
{
	return lhs.value < rhs.value;
}

ostream& operator<<(ostream& os, const Test& item)
{
	return os << item.value;
}

//这个程序在vs2019上是可以运行的，我不知道在g++上为什么不能运行？
int main(void)
{
	Test test1(1), test2(2), test3(-11);
	set<Test, bool (*)(const Test&, const Test&)> testset(tcompare);
	testset.insert(test1);
	testset.insert(test2);
	testset.insert(test3);
	//testset.insert(44);//使用explicit可以限制隐式类型转换构造
	testset.emplace(44);//但是可以通过emplace成员函数在内存中直接构造一个元素
	//testset.emplace(testset.end(), 222);//编译器会提示没有接受两个参数的成员函数，可能是微软的STL没有加入这个成员函数？
	testset.insert(testset.begin(), Test(22));
	//testset.emplace(testset.begin(), 3333);
	decltype(testset)::const_iterator iter = testset.begin();

	for (; iter != testset.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	map<Test, size_t, bool (*)(const Test&, const Test&)> testmap(tcompare);
	auto repair = testmap.emplace(22, 32);
	//repair = testmap.emplace(22, 22);//同一个关键字只能插入一次，若没有插入返回的pair中的第二个成员就会是false
	auto insert_iter=testmap.insert(testmap.end(), make_pair(Test(21), 33));
	//auto test_iter = testmap.emplace(testmap.begin(), Test(4554), 32);

	if (repair.second)
	{
		for (const auto& elem : testmap)
			cout << elem.first << " occurs " << elem.second << endl;
	}

	return 0;
}
