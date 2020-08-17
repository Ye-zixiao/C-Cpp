#include<iostream>
#include<iterator>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
using namespace::std;

class Test {
	friend istream& operator>>(istream& is, Test& item);
public:
	Test():value1(0),value2(0){}
	Test(int val1,int val2):value1(val1),value2(val2){}

	/*void operator=(const Test& item) {
		value1 = item.value1;
		value2 = item.value2;
	}*/
	int sum(void)const { return value1 + value2; }

private:
	int value1, value2;

};

istream& operator>>(istream& is, Test& item)
{
	return is >> item.value1 >> item.value2;
}

ostream& operator<<(ostream& os, const Test& item)
{
	return os << "Current Sum:" << item.sum();
}

int main(void)
{
	istream_iterator<Test> in_iter(cin), eof;
	ostream_iterator<Test> out_iter(cout, "\n");
	Test test;
	while (in_iter != eof)//在每一次判断的时候也会先读取一次数据
	{
		out_iter = test;
		cout << "Next Sum:" << in_iter->sum() << endl;//下一个待输入的数据，但是目前还没有输入
		test = *in_iter++;//将上一次输入的数据输入到test当中,并从cin中读取下一次的数据
	}
	out_iter=test;//没有数据读取了，就把当前的数据打印出来

	return 0;
}
