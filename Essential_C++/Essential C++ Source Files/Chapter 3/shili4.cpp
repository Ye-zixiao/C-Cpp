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
	/*typename vector<string>::const_iterator iter = st_vec.begin();//������ʽ�Ͳ�һ���㣬
	for (; iter != st_vec.end(); iter++)                            //��ʵ����ʡ����typenameҲ��û�й�ϵ��
		cout << *iter << endl;*/
	display(st_vec);

	return 0;
}

/*template<typename elemtype>�����ʾ��
void display(const vector<elemtype>& vec, ostream& os)
{
	vector<elemtype>::iterator first_it = vec.begin();
	vector<elemtype>::iterator end_it = vec.end();

	for (; first_it != end_it; iter++)
		os << *first_it << ' ';
	os << endl;
}*/

template<typename elemtype>
void display(const vector<elemtype>& vec,ostream &os)//Ĭ��ֵֻ������һ��
{
	typename vector<elemtype>::const_iterator first = vec.begin();
	typename vector<elemtype>::const_iterator last = vec.end();/*��ʹ��ģ�������ڲ���type������ָconst_iterator��ʱ��
																������߱���������һ��type�����Ǳ���*/

	for (; first != last; first++)
		os << *first << endl;
}
