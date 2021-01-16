#include<iostream>
#include<string>
#include<cctype>
#include<vector>
using namespace::std;

void print_first_prag(vector<string>& svec);
void transfer_upper(vector<string>& svec);
void input_words(vector<string>& svec);

int main(void)
{
	vector<string> svec;
	input_words(svec);
	print_first_prag(svec);

	transfer_upper(svec);
	print_first_prag(svec);

	return 0;
}

void print_first_prag(vector<string>& svec)
{
	for (auto con_iter = svec.cbegin();
		con_iter != svec.cend()&&!con_iter->empty(); ++con_iter)//迭代器未迭代到最后且所指向的对象非空字符串
		cout << *con_iter << ' ';
	cout << endl;

	return;
}

void transfer_upper(vector<string>& svec)
{
	for (auto iter = svec.begin(); iter != svec.end() && !iter->empty(); ++iter)
		for (auto char_iter = iter->begin(); char_iter != iter->end(); ++char_iter)
			*char_iter = toupper(*char_iter);
	return;
}

void input_words(vector<string>& svec)
{
	string temp;
	cout << "Enter the words for this program:\n";
	while (cin >> temp)
		svec.push_back(temp);

	return;
}
