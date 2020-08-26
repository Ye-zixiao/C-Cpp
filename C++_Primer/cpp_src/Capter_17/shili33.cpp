#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
using namespace::std;

int main(void)
{
	fstream InOut("key_world.txt", fstream::ate | fstream::in | fstream::out);
	if (!InOut) {
		cerr << "Can't open this file" << endl;
		return EXIT_FAILURE;
	}

	auto end_mark = InOut.tellg();
	//cout << end_mark << endl;
	InOut.seekg(0, fstream::beg);
	size_t cnt = 0;
	for (string line; InOut && InOut.tellg() != end_mark && getline(InOut, line);) {
		cnt += line.size() + 1;
		auto pre_mark = InOut.tellg();
		InOut.seekp(0, fstream::end);
		//cout << cnt;
		InOut << cnt;
		if (pre_mark != end_mark)InOut << ' ';
		InOut.seekg(pre_mark);
	}
	InOut.seekp(0, fstream::end);
	InOut << '\n';

	InOut.seekg(0, fstream::beg);
	size_t sz = 0;
	for (char ch; InOut >> ch; ++sz);
	cout << "text char's number: " << sz << endl;

	return 0;
}
