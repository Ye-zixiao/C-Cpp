#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include<iterator>
#include<cstring>
using namespace::std;

int main(void)
{
	constexpr unsigned size = 100;
	const char con_str[] = "hello world";
	string str(con_str);				//允许一个以空字符结尾的字符数组作为string对象的初始值
	cout << str << endl;

	char char_cpy[size];
	strcpy(char_cpy, str.c_str());
	cout << char_cpy << endl;

	for (const char* pchar=str.c_str(); *pchar; ++pchar)
		cout << *pchar;
	cout << endl;

	string str_test("test ");
	cout << str_test + char_cpy << endl;//允许string对象的加法运算中以空字符作为结尾的字符数组作为运算对象

	str_test += char_cpy;
	cout << str_test << endl;			//允许复合赋值运算符中以空字符作为结尾的字符数组作为右侧运算对象

	int int_arr[] = { 1,2,3,4,5,6 };
	vector<int> ivec(begin(int_arr), end(int_arr));
	for (auto i : ivec)
		cout << i << ' ';
	cout << endl;
	vector<int> ivec_sub(int_arr + 1, int_arr + 3);//第二参数作为尾后指针，并不会被纳入到vector中
	for (auto i : ivec_sub)
		cout << i << ' ';
	cout << endl;

	return 0;
}
