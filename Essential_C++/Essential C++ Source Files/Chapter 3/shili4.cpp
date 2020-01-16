#include<iostream>
#include<vector>
#include<string>
using namespace std;

//template<typename elemtype>
//void display(const vector<elemtype>& vec, ostream& os = cout);

template<typename elemtype>
void display(const vector<elemtype>& vec,ostream &os=cout);

int main(void)
{
	string st_arr[3] = { "hello world","niubiliaty","fuck you" };
	vector<string> st_vec(st_arr, st_arr + 3);
	/*display(st_vec);*/
	/*typename vector<string>::const_iterator iter = st_vec.begin();//这个表达式就不一样点，
	for (; iter != st_vec.end(); iter++)                            //事实上它省略了typename也是没有关系的
		cout << *iter << endl;*/
	display(st_vec);

	return 0;
}

/*template<typename elemtype>错误的示范
void display(const vector<elemtype>& vec, ostream& os)
{
	vector<elemtype>::iterator first_it = vec.begin();
	vector<elemtype>::iterator end_it = vec.end();

	for (; first_it != end_it; iter++)
		os << *first_it << ' ';
	os << endl;
}*/

template<typename elemtype>
void display(const vector<elemtype>& vec,ostream &os)//默认值只能声明一次
{
	typename vector<elemtype>::const_iterator first = vec.begin();
	typename vector<elemtype>::const_iterator last = vec.end();/*在使用模板类型内部的type（这里指const_iterator）时，
																必须告诉编译器这是一个type而不是变量*/

	for (; first != last; first++)
		os << *first << endl;
}
