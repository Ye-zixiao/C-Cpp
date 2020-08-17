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
	string str(con_str);				//����һ���Կ��ַ���β���ַ�������Ϊstring����ĳ�ʼֵ
	cout << str << endl;

	char char_cpy[size];
	strcpy(char_cpy, str.c_str());
	cout << char_cpy << endl;

	for (const char* pchar=str.c_str(); *pchar; ++pchar)
		cout << *pchar;
	cout << endl;

	string str_test("test ");
	cout << str_test + char_cpy << endl;//����string����ļӷ��������Կ��ַ���Ϊ��β���ַ�������Ϊ�������

	str_test += char_cpy;
	cout << str_test << endl;			//�����ϸ�ֵ��������Կ��ַ���Ϊ��β���ַ�������Ϊ�Ҳ��������

	int int_arr[] = { 1,2,3,4,5,6 };
	vector<int> ivec(begin(int_arr), end(int_arr));
	for (auto i : ivec)
		cout << i << ' ';
	cout << endl;
	vector<int> ivec_sub(int_arr + 1, int_arr + 3);//�ڶ�������Ϊβ��ָ�룬�����ᱻ���뵽vector��
	for (auto i : ivec_sub)
		cout << i << ' ';
	cout << endl;

	return 0;
}
