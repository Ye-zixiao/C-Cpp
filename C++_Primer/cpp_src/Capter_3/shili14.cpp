#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace::std;

int main(void)
{
	string word;
	vector<string> words;
	cout << "Enter the word for this program!" << endl;
	while (cin >> word)
	{
		words.push_back(word);
	}
	cout << "Input ends" << endl;
	cout << "After transfering:" << endl;

	for (auto& str : words)//要知道一点就是auto使得引用绑定的是引用所指向的对象
		for (auto& c : str)//所以c引用的是（str引用所指向的字符串的char对象）
			c = toupper(c);

	for (auto& str : words)
		cout << str << " ";
	cout << endl;

	return 0;
}
