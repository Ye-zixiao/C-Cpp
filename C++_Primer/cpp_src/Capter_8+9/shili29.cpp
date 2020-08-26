#include<iostream>
#include<vector>
#include<array>
#include<string>
using namespace::std;

string& find_insert(string& s, const string& oldVal, const string& newVal)
{
	auto iter = s.begin();
	while (iter != s.end() - oldVal.size())
	{
		if (oldVal == string(iter, iter + oldVal.size()))
		{
			iter = s.erase(iter, iter + oldVal.size());
			iter = s.insert(iter, newVal.begin(), newVal.end());
			iter += newVal.size();
		}
		else ++iter;
	}
	return s;
}

string& find_insert2(string& s, const string& oldVal, const string& newVal)
{
	string::size_type i = 0;
	while (i != s.size() - oldVal.size())
	{
		if (oldVal == string(s, i, oldVal.size()))
			//有一种思路就是先去一个一个字符去比较，因为如果连第一个字符都不一样，那么后面的字符串怎么会一样呢？
		{
			s.replace(i, oldVal.size(), newVal);
			i += newVal.size();
		}
		else ++i;
	}
	return s;
}

string& add_pre_suffix(string& s, const string& prefix, const string& suffix)
{
	s.insert(s.begin(), prefix.begin(), prefix.end());
	return s.append(suffix);
}

string& add_pre_suffix2(string& s, const string& prefix, const string& suffix)
{
	s.insert(0, prefix);
	return s.insert(s.size(), suffix);
}

int main(void)
{
	string s = "hello world hello world show code";
	cout << find_insert(s, "hello", "okay") << endl;
	cout << find_insert2(s, "okay", "hello") << endl;

	string name("Ye-zixiao");
	//cout << add_pre_suffix(name, "Mr.", " --China") << endl;

	cout << add_pre_suffix2(name, "Mr.", " --China") << endl;


	return 0;
}
