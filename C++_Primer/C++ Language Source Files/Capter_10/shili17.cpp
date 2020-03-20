#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
//#include<>
using namespace::std;

template<typename Type>
ostream& operator<<(ostream& os, const vector<Type>& tvec)
{
	for (auto iter = tvec.begin(); iter != tvec.end(); ++iter)
		os << *iter << ' ';
	return os;
}

int main(void)
{
	vector<int> ivec(10);
	for (decltype(ivec)::size_type i = 0; i < ivec.size(); ++i)
		ivec[i] = i;
	cout << ivec << endl;

	decltype(ivec)::size_type i = 0;
	for (auto f = [&] {++i; }; i < ivec.size(); f())
		cout << ivec[i] << ' ';
	cout << endl;


	int value = 10;
	auto f = [value]()mutable {return ++value; };
	/*lambda�����岻��������һ�������壬��������һ��δ�����������͡���Ĭ������£������б��в���ı������ֻ��Ϊ
	��δ�������ڵ����ݳ�Ա��������������Ϊ������������ڸ�δ�����࣬lambda������ĺ���������Ϊ�൱����ͨ���е�const
	��Ա��������lambda����ʵ��ִ�й������ǲ��ܸı�������ݳ�Ա��ֵ��
		���ǣ����ڲ����б�������mutable�ؼ��ֿ���ʹ�ø�δ����������ݳ�Ա�����統ǰ��value�����һ��mutable���ݳ�Ա��
	������ʹ��lambda������const��Ա������ִ��ʱҲ���Ըı�����ݳ�Ա��
		Ȼ�����ı����ڵ�mutable���ݳ�Աvalue������ԭ��δ������lambda������ľֲ�����value�ܹ���lambda������ı䣬��Ϊ
	�����Ǳ�ֵ����ģ��������ڵ�value������ľֲ�����value��������ͬ�Ķ���*/
	cout << f() << endl;
	cout << f() << endl;//�ı����δ���������ڵ����ݳ�Աvalue
	cout << value << endl;//��ԭ���ľֲ�����valueû�б��ı�

	return 0;
}
