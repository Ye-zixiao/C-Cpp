#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Base {
public:
	Base(T v) :value(v){}

	T getvalue(void) const {
		return value;
	}

	void modify(T new_value) {
		value = new_value;
	}

private:
	T value;
};

template<typename T>
class Derived :private Base<T> {
public:
	//using Base<T>::getvalue;
	Derived(T v,const string&s):
		Base<T>(v),str(s){}

	T getval(void) const {
		/*���ڵ�һ��������̳���һ��ģ�廯�Ļ���ʱ����������Ĭ�ϵ���Ϊģ�����������������汾
		(������������汾���ܾ�����һ����ģ�岻һ���Ľӿ�)�����������ȷ���ԣ����Ա������ڲ���
		�������ֵ�ʱ�򲻻ᵽ������������в�����ص����֣�������������ʽ��this->,using�����ȷ�
		ʽ����ָ������������޷�ͨ��*/
		return this->getvalue();//right
		//return Base<T>::getvalue();//right
		//return getvalue();//wrong

		//return getvalue();//ʹ���������using������right
	}

	void modify_val(T new_val) {
		this->modify(new_val);
	}

	const string& getstr(void) const {
		return str;
	}

private:
	string str;
};

int main(void)
{
	Derived<int> item(342, "hello world");
	cout << item.getval() << item.getstr() << endl;

	return 0;
}
