#include<iostream>
#include<vector>
#include<string>
#include<functional>
using namespace std;

template<typename elemType, typename Comp = less<elemType> >			/*���ڶ�����Щ���Ͷ��ԣ����û��typename Comp = less<elemType>��
																		ִ���������صĺ���ʱ��Ĭ�ϻ���Ϊ������������صıȽ�������ģ�
																		����˵<�����������������������Ч�ġ�������ʵ�ϲ�һ����������
																		��������������������صıȽ����������ʹ�ã�����Ҳ���ܽ����Զ���
																		�ıȽϡ�����˵����Ƚ������ַ����ĳ��ȣ�Ȼ���������ϻ��ߵ�ǰ�Ŀ�
																		�в�û����صĺ���������������Ե��á���ʱ���ܲ�����ڶ�����ģ��
																		��������Ϊ���ṩĬ�ϵĲ����������Ϳ��Խ��Ƚ���������ඨ��Ӷ�������
																		�ñ�ĺ���������Ϊ���������¸������µıȽϹ���
																		*/
class LessThanPred
{
public:
	LessThanPred(const elemType& val):_val(val) {}

	bool operator()(const elemType& val) const
	{
		Comp lesst;					//��ʼ���б��޷�ת����Comp
		return lesst(val, _val);
		/*return Comp(val, _val);*/
	}
	void val(const elemType& newval) { _val = newval; }
	elemType val() const { return _val; }

private:
	elemType _val;
};

class StringLess
{
public:
	bool operator()(const string& st1, const string& st2) const
	{
		return st1.size() < st2.size();
	}
};

int main(void)
{
	LessThanPred<int> lti(20);
	if (lti(11))
		cout << 11 << " less than " << lti.val() << endl;

	LessThanPred<string, StringLess> ltstr("moon");
	if (ltstr("hello"))
		cout << "hello" << " less than " << ltstr.val() << endl;
	else
		cout << "hello" << " not less than " << ltstr.val() << endl;

	return 0;
}
