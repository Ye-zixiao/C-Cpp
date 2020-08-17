#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace::std;

class sizeComp {
public:
	sizeComp(size_t l,size_t u):_lower(l),_upper(u){}

	bool operator()(const string& str) const {
		return _lower <= str.size() && str.size() <= _upper;
	}

private:
	size_t _lower;
	size_t _upper;
};

int main(void)
{
	vector<sizeComp> sc;//函数对象的vector，每一个元素分别对应一个字符串长度
	map<size_t, size_t> size_count;//记录 字符串长度----> 个数 的键值关联容器
	ifstream infile("infile.txt", ifstream::in);
	if (!infile) {
		cerr << "Can't open this file" << endl;
		return -1;
	}
	for (size_t i = 1; i <= 10; ++i) {//初始化
		size_count[i] = 0;
		sc.push_back(sizeComp(i, i));
	}

	for (string word; infile >> word;) {
		for (const auto& elem : sc)
			if (elem(word))
				++size_count[word.size()];
	}

	for (const auto& elem : size_count)
		cout << "String's size == " << elem.first << " occurs " << elem.second << " time(s)" << endl;

	return 0;
}
