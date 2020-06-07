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
	//fuc(*iter)等价于(*iter->*p)()//其中p是fuc这个function类对象中所保存的指向成员函数的指针
	/*
		fuc中的类重载了函数调用运算符：
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
