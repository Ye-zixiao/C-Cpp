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

	for (auto& str : words)//Ҫ֪��һ�����autoʹ�����ð󶨵���������ָ��Ķ���
		for (auto& c : str)//����c���õ��ǣ�str������ָ����ַ�����char����
			c = toupper(c);

	for (auto& str : words)
		cout << str << " ";
	cout << endl;

	return 0;
}
