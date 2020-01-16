#include"Triangular.h"

vector<int> Triangular::_elems;								//��̬��Ա������Ҫ�����ⵥ������ռ�

Triangular::
Triangular(int len, int bp)									//���캯��:��ʼ�㵽���һ��vectorԪ���е����ݳ���Ϊ_length
{
	_length = len > 0 ? len : 1;
	_begin_pos = bp > 0 ? bp : 1;
	_next = _begin_pos - 1;
	gen_elements(_length+_next);
}

Triangular& Triangular::
operator=(const Triangular& rhs)
{
	this->_length = rhs._length;
	this->_begin_pos = rhs._begin_pos;
	this->_next = rhs._next;
	gen_elements(_length+_next);

	return *this;
}

bool Triangular::
is_elem(int value)											//�ж�һ����ֵ�Ƿ���Triangular�����еĳ�Ա
{
	if (!_elems.size() || _elems[_elems.size() - 1] < value)
		gen_elements(value);

	vector<int>::iterator found_it;
	vector<int>::iterator end_it = _elems.end();
	found_it = find(_elems.begin(), end_it, value);
	return found_it != end_it;
}

void Triangular::
gen_elements(int length)									//����ָ�����ȵ�Triangular���д�ŵ�vector��������
{
	if (length<0 || length>_max_elems)
	{
		cerr << "Error!" << endl;
		return;
	}

	if (_elems.size() < (unsigned)length)
	{
		int index = _elems.size() ? _elems.size() + 1 : 1;
		for (; index <= length; ++index)
			_elems.push_back(index * (index + 1) / 2);
	}
}

void Triangular::
gen_elems_to_value(int value)								/*���ɵ�С�ڵ���ָ����ֵ��Triangular���У�����������еĳ�Ա��
															�����˳���������Ǿ���ʾ����*/
{
	int index = _elems.size();
	if (!index)
	{
		_elems.push_back(1);
		index = 1;
	}
	while (_elems[index - 1] < value && index < _max_elems)
	{
		++index;
		_elems.push_back(index * (index + 1) / 2);
	}
	if (index == _max_elems)
		cerr << "Error" << endl;
}

void Triangular::
display(int length, int begin_pos, ostream& os) const			//��ͨ��Ա���������Է��ʾ�̬��Ա��������ͨ�ĳ�Ա����
{
	int index = begin_pos - 1;
	for (; index < length+_next; ++index)
		os << _elems[index] << ' ';
	os << endl;
}

ostream& operator<<(ostream& os, const Triangular& rhs)			/*ʹ��const����Triangular��������Ҫ��֤�������ж�rhs�ĳ�Ա����
																��������Ϊconst��Ա�������������������Ϊ�������ܻ��޸�ԭ��������
																���������ձ��벻ͨ��*/
{
	os << "(" << rhs.begin_pos() << ","
		<< rhs.length() << ")";

	rhs.display(rhs.length(), rhs.begin_pos(), os);
	return os;
}

istream& operator>>(istream& is, Triangular& rhs)				/*ʹ���������������ʹ�����������ܹ�ֱ�Ӷ�ָ���������в�������*/
{
	char ch1, ch2;
	int bp, len;

	is >> ch1 >> bp >> ch2 >> len;
	rhs.begin_pos(bp);
	rhs.length(len);
	rhs.next_reset();

	return is;
}