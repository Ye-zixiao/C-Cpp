#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace::std;

int main(void)
{
	vector<string*> pstrvec{ new string("hello"),new string(),new string(),
		new string("world"),new string("china"),new string(),new string() };
	function<bool(const string*)> fuc = &string::empty;
	cout << count_if(pstrvec.begin(), pstrvec.end(), fuc) << endl;
	//fuc(*iter)�ȼ���(*iter->*p)()//����p��fuc���function��������������ָ���Ա������ָ��
	/*
		fuc�е��������˺��������������
		class fuc{
		public:
			bool operator()(const string* &pstr){
				return (*pstr->*p)();
			}
		}
	*/
	for_each(pstrvec.begin(), pstrvec.end(), [](string*& p) {delete p; });

	return 0;
}
