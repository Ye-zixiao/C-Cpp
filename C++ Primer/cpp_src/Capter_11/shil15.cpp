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

//���������vs2019���ǿ������еģ��Ҳ�֪����g++��Ϊʲô�������У�
int main(void)
{
	Test test1(1), test2(2), test3(-11);
	set<Test, bool (*)(const Test&, const Test&)> testset(tcompare);
	testset.insert(test1);
	testset.insert(test2);
	testset.insert(test3);
	//testset.insert(44);//ʹ��explicit����������ʽ����ת������
	testset.emplace(44);//���ǿ���ͨ��emplace��Ա�������ڴ���ֱ�ӹ���һ��Ԫ��
	//testset.emplace(testset.end(), 222);//����������ʾû�н������������ĳ�Ա������������΢���STLû�м��������Ա������
	testset.insert(testset.begin(), Test(22));
	//testset.emplace(testset.begin(), 3333);
	decltype(testset)::const_iterator iter = testset.begin();

	for (; iter != testset.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	map<Test, size_t, bool (*)(const Test&, const Test&)> testmap(tcompare);
	auto repair = testmap.emplace(22, 32);
	//repair = testmap.emplace(22, 22);//ͬһ���ؼ���ֻ�ܲ���һ�Σ���û�в��뷵�ص�pair�еĵڶ�����Ա�ͻ���false
	auto insert_iter=testmap.insert(testmap.end(), make_pair(Test(21), 33));
	//auto test_iter = testmap.emplace(testmap.begin(), Test(4554), 32);

	if (repair.second)
	{
		for (const auto& elem : testmap)
			cout << elem.first << " occurs " << elem.second << endl;
	}

	return 0;
}
