#include<iostream>
using namespace::std;

/*
1��public�̳У�
������ĳ�Ա��������Ԫ���Է��ʻ����е�public��protected��Ա�����ǲ��ܷ��ʻ����е�private��Ա��
�������������û���ʵ������ֻ�ܷ��ʻ����е�public��Ա�����������Ի����е�public����public���������е�protected����protected�������е�private������û�м̳�Ҳ���ܷ���
2��private�̳У�
������ĳ�Ա��������Ԫ���Է��ʻ����е�public��protected��Ա�����ǲ��ܷ��ʻ����е�private��Ա��
�����������û���ʵ������ʲôҲ���ܷ��ʣ����������Ի����е�public�����private�������е�protected�����private�������е�private�����ܼ̳�Ҳ���ܷ���
3��protected�̳У�
������ĳ�Ա��������Ԫ���Է��ʻ����е�public��protected��Ա�����ǲ��ܷ��ʻ����е�private��Ա��
�����������û���ʵ������ʲôҲ���ܷ��ʣ����������Ի����е�public�����protected�������е�protected����protected�������е�private��û�м̳�Ҳ���ܷ���

- �����еķ���˵����������������ĳ�Ա�ܷ���ʻ���ĳ�Ա������������ĳ�Ա����Ԫ�ܹ����ʻ����е�public��protected��Ա
- �����б��еķ���˵����������������ʵ�������ܷ���ʻ����е�public��Ա������Ӱ���������������ĳ�Ա����ֱ�ӻ���ĳ�Ա����Ȩ��
*/

class Base {
public:
	Base() = default;

	int pub_mem = 0;
protected:
	int pro_mem = 0;
private:
	int pri_mem = 0;
};

class Derived_pub :public Base {
public:
	Derived_pub():Base(){}

	void func(void) {
		this->pro_mem = 0;
		this->pub_mem = 0;
	}
};

class Derived_pri :private Base {
public:
	Derived_pri():Base(){}

	void func(void) {
		this->pro_mem = 0;
		this->pub_mem = 0;
	}
};

class Derived_pro :protected Base {
public:
	Derived_pro():Base(){}

	void func(void) {
		this->pro_mem = 0;
		this->pub_mem = 0;
	}
};

class Derived_from_Derived_pri :public Derived_pri {
public:
	Derived_from_Derived_pri():Derived_pri(){}

	void func(void) {
		//�����е�pub_mem��pro_mem����Derived_from_Derived_pri����Զ������private����
	}
};

class Derived_from_Derived_pro :public Derived_pro {
public:
	Derived_from_Derived_pro():Derived_pro(){}

	void func(void) {
		this->pro_mem;//��ʱ�����е�pub_mem��pro_mem����Derived_from_Derived_pro����Զ���protect��Ա
		this->pub_mem;
	}
};

int main(void)
{
	Base item;
	cout << item.pub_mem << endl;

	Derived_pub item_pub;
	cout << item_pub.pub_mem << endl;

	Derived_pri item_pri;
	//cout << item_pri.pub_mem << endl;

	Derived_pro item_pro;
	//cout << item_pro.pub_mem << endl;

	Derived_from_Derived_pri item_pri_pub;
	//cout << item_pri_pub.pub_mem << endl;

	Derived_from_Derived_pro item_pro_pub;
	//cout << item_pro_pub.pub_mem << endl;

	return 0;
}
