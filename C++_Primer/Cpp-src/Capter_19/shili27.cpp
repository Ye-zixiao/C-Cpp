#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
using namespace::std;
using namespace::placeholders;

int main(void)
{
	vector<string> strvec{
		"hello","world","","",
		"china","japan","joker",
		"","","doyoudo","",""
	};
	cout << count_if(strvec.begin(), strvec.end(), mem_fn(&string::empty))
		<< endl;
	cout << count_if(strvec.begin(), strvec.end(), bind(&string::empty, _1))
		<< endl;

	auto f = bind(&string::empty, _1);
	//���ɵĿɵ��ö���ʹ��(strvec.back().*p)()����empty��Ա����
	if (f(strvec.back()))
		cout << "empty" << endl;
	//���ɵĿɵ��ö���ʹ��(&strvec.back()->*p)()����empty��Ա���������������pָ���ǿɵ��ö��󱣴�ĳ�Ա����ָ��
	if (f(&strvec.back()))
		cout << "second empty" << endl;

	return 0;
}
