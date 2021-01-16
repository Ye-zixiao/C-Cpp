#include<iostream>
#include<vector>
#include<algorithm>
//#include<functional>
using namespace std;

class LessThan
{
private:
	int _value;

public:
	LessThan(int value) :_value(value){}

	int comp_value() const { return _value; }
	void comp_value(int value) { _value = value; }

	bool operator()(int value) const;				/*��������أ�ʹ�ô���Less_Than����󼴵��ڴ���һ����������
													���������ȫ���Գ䵱����ָ��������*/
};

inline bool LessThan::
operator()(int value) const
{
	return value < _value;
}

int less_than_count(const vector<int>& vec, int comp);
void print_less_than(const vector<int>& vec, int comp, ostream& os = cout);

int main(void)
{
	int arr[16] = { 17,12,44,9,18,45,6,14,23,67,
				9,0,27,55,8,16 };
	vector<int> vec(arr, arr + 16);

	int comp_val = 20;

	cout << "Number of elements less than "
		<< comp_val << " are "
		<< less_than_count(vec, comp_val)
		<< ":" << endl;
	print_less_than(vec, comp_val);

	return 0;
}

int less_than_count(const vector<int>& vec, int comp)
{
	LessThan less_than_val(comp);						//��ʼ��һ���������󣬴ﵽ���뺯��ָ����ͬ������

	int count = 0;
	for (int index = 0; index < vec.size(); ++index)
		if (less_than_val(vec[index]))					//��������ʹ�ø���ֵС���趨ֵ�Ļ����᷵��һ��true���������false
			++count;

	return count;
}

void print_less_than(const vector<int>& vec, int comp, ostream& os)
{
	LessThan lt(comp);

	vector<int>::const_iterator it = vec.begin();
	vector<int>::const_iterator end_it = vec.end();

	os << "elements less than " << lt.comp_value() << endl;
	while ((it = find_if(it, end_it, lt)) != end_it)
	{
		os << *it << ' ';
		++it;
	}
	cout << endl;
}
