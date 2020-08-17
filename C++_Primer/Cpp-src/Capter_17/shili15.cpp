#include<iostream>
#include<string>
#include<regex>
using namespace::std;

/*
�ʱࣺ5Ϊ��ֵ��-����û�У���4λ��ֵ��
*/

bool valid(const smatch& sm) {
	if (sm[3].matched)
		return true;
	else
		return !sm[2].matched;
}

int main(void)
{
	string postnum;
	regex re("(\\d{5})([- .])?(\\d{4})?");
	while (getline(cin, postnum)) {
		smatch result;
		for (sregex_iterator iter(postnum.begin(), postnum.end(), re), end_iter;
			iter != end_iter; ++iter)
			if(valid(*iter))
				cout << "exsiting phone number: " << iter->str(0) << endl;
	}
	return 0;
}
