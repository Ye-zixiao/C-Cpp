#ifndef TRIANGULAR_H_
#define TRIANGULAR_H_

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Triangular_iterator											//����ĳɹ����л����ඨ����Ⱥ�˳���й�
{
public:
	Triangular_iterator(int index) :_index(index - 1) {}

	bool operator==(const Triangular_iterator&) const;
	bool operator!=(const Triangular_iterator&) const;
	int operator*() const;
	Triangular_iterator& operator++();
	Triangular_iterator operator++(int);

private:
	void check_integrity() const;
	int _index;

};

class Triangular
{
	/*friend int Triangular_iterator::operator*() const;
	friend void Triangular_iterator::check_integrity() const;*/
	friend class Triangular_iterator;								//Triangular_iteratorֻ�е��ȶ��������²�����ȷ����
																	//Triangular_iterator�����г�Ա��������Ϊ��Triangulars����Ԫ
public:
	Triangular(int len = 1, int bp = 1);
	Triangular& operator=(const Triangular& rhs);					//������ֵ��������أ���������������ʵ���ĸ���
	
	int length() const { return _length; }
	void length(int len) { _length = len; }
	void begin_pos(int bp) { _begin_pos = bp; }
	int begin_pos() const { return _begin_pos; }
	void next_reset() const { _next = _begin_pos - 1; }
	void display(int length, int begin_pos, ostream& os) const;

	typedef Triangular_iterator iterator;							/*��iteratorǶ����ÿһ�����ṩiterator��������class�ڣ����ǾͿ���
																		�ṩ������ͬ���ƵĶ������*/
	Triangular_iterator begin() const
	{
		return Triangular_iterator(_begin_pos);						//�����ײ�����
	}
	Triangular_iterator end() const
	{
		return Triangular_iterator(_begin_pos + _length);			//����β������
	}

	static bool is_elem(int value);
	static void gen_elements(int length);
	static void gen_elems_to_value(int value);
	
private:
	static const int _max_elems = 25;
	static vector<int> _elems;
	int _length;						//���г���
	int _begin_pos;						//���п�ʼ�±꣬��һ����1�����Ը����û�����
	mutable int _next;
};

ostream& operator<<(ostream& os, const Triangular& rhs);			//ʹ���������������ﵽֱ�����������е����ݵ�Ŀ��
istream& operator>>(istream& is, Triangular& rhs);					//ʹ����������������ﵽֱ�ӽ��������뵽������е�Ŀ��

/*====================Triangular�ĵ����������������========================*/
inline bool Triangular_iterator::
operator==(const Triangular_iterator &rhs) const					//�жϵ�ǰ���������������������Ƿ���ͬ
{
	return _index == rhs._index;
}

inline bool Triangular_iterator::
operator!=(const Triangular_iterator& rhs) const					//�жϵ�ǰ�����������Ƿ���ͬ
{
	return !(*this == rhs);
}

inline int Triangular_iterator::									//��Triangular���������н����ã�ͬʱ����������������Ƿ���ȷ
operator*() const
{
	check_integrity();
	return Triangular::_elems[_index];/*��������������������Ǳ���Ҫ�ӵġ�Ϊʲô����
									  ����Ϊ��ǰ�ĳ�Ա���������ڵ�������ģ�������triangular��ģ�
									  ���Է���triangular�е�_elems��̬��Ա������Ҫ�ڵ�ǰTriangular_iterator��Ա������
									  ָ�����������������ģ�ͬʱ��Ҳ�Ƿ��ʾ�̬��Ա���ݵĹ涨��������*/
}

inline void Triangular_iterator::
check_integrity() const												//�Ե��������������а�ȫ�Լ��
{
	if ((unsigned)_index == Triangular::_max_elems)
		cerr << "Error!" << endl;
	
	if ((unsigned)_index >= Triangular::_elems.size())				/*�������������������������̬����vectorû����ô������ݣ�
																		����Ҫ����Triangular�еĳ�Ա����ȥ����Ҫ������������*/
		Triangular::gen_elements(_index + 1);
}

inline Triangular_iterator& Triangular_iterator::
operator++()														//����������������ǰ׺�汾��
{
	++_index;
	check_integrity();
	return *this;
}

inline Triangular_iterator Triangular_iterator::
operator++(int)														//������������������׺�汾��
{
	Triangular_iterator tmp = *this;
	check_integrity();
	return tmp;
}

#endif