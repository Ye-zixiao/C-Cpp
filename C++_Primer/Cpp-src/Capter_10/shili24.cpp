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
	while (in_iter != eof)//��ÿһ���жϵ�ʱ��Ҳ���ȶ�ȡһ������
	{
		out_iter = test;
		cout << "Next Sum:" << in_iter->sum() << endl;//��һ������������ݣ�����Ŀǰ��û������
		test = *in_iter++;//����һ��������������뵽test����,����cin�ж�ȡ��һ�ε�����
	}
	out_iter=test;//û�����ݶ�ȡ�ˣ��Ͱѵ�ǰ�����ݴ�ӡ����

	return 0;
}
