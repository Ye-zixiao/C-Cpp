#include"Triangular.h"

vector<int> Triangular::_elems;								//静态成员变量需要在类外单独分配空间

Triangular::
Triangular(int len, int bp)									//构造函数:起始点到最后一个vector元素中的数据长度为_length
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
is_elem(int value)											//判断一个数值是否是Triangular数列中的成员
{
	if (!_elems.size() || _elems[_elems.size() - 1] < value)
		gen_elements(value);

	vector<int>::iterator found_it;
	vector<int>::iterator end_it = _elems.end();
	found_it = find(_elems.begin(), end_it, value);
	return found_it != end_it;
}

void Triangular::
gen_elements(int length)									//生成指定长度的Triangular数列存放到vector向量当中
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
gen_elems_to_value(int value)								/*生成到小于等于指定数值的Triangular数列，如果它是数列的成员就
															正常退出，如果不是就提示错误*/
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
display(int length, int begin_pos, ostream& os) const			//普通成员函数都可以访问静态成员变量和普通的成员变量
{
	int index = begin_pos - 1;
	for (; index < length+_next; ++index)
		os << _elems[index] << ' ';
	os << endl;
}

ostream& operator<<(ostream& os, const Triangular& rhs)			/*使用const声明Triangular对象后必须要保证里面所有对rhs的成员函数
																都被声明为const成员函数，否则编译器会认为这样可能会修改原来的数据
																而导致最终编译不通过*/
{
	os << "(" << rhs.begin_pos() << ","
		<< rhs.length() << ")";

	rhs.display(rhs.length(), rhs.begin_pos(), os);
	return os;
}

istream& operator>>(istream& is, Triangular& rhs)				/*使用重载输入运算符使得输入数据能够直接对指定类对象进行参数设置*/
{
	char ch1, ch2;
	int bp, len;

	is >> ch1 >> bp >> ch2 >> len;
	rhs.begin_pos(bp);
	rhs.length(len);
	rhs.next_reset();

	return is;
}