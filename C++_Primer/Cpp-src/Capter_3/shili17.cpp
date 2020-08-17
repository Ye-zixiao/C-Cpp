#include<iostream>
#include<string>
#include<cctype>
using namespace::std;

int main(void)
{
	string str = "hello world";
	for (auto iter = str.begin(); iter != str.end() && !isspace(*iter); ++iter)
		*iter = toupper(*iter);

	cout << str << endl;

	return 0;
}

/*
#include<iostream>
#include<string>
#include<vector>
using namespace::std;

int main(void)
{
	vector<string> str_vec(10, "hello world");
	for (auto iter = str_vec.begin(); iter != str_vec.end(); ++iter)
		if (iter == str_vec.begin())            //在使用迭代器的循环中，不能向迭代器指向的容器添加元素
			str_vec.push_back("nb");
	for (const string str : str_vec)
		cout << str << endl;

	return 0;
}
*/
