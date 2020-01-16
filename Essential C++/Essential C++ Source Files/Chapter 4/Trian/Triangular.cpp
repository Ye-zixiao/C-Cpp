//triangular.cpp

#include "triangular.h"

vector<int> Triangular::_elems;

Triangular::Triangular(int len, int beg_pos)
	:_length(len > 0 ? len : 1), _beg_pos(beg_pos > 0 ? beg_pos : 1)
{
	_next = _beg_pos - 1;
	int elem_cnt = _beg_pos + _length;

	if (_elems.size() < (unsigned)elem_cnt)
		gen_elements(elem_cnt);
}

Triangular& Triangular::copy(const Triangular& rhs)
{
	_length = rhs._length;
	_beg_pos = rhs._beg_pos;
	_next = rhs._beg_pos - 1;

	_elems = rhs._elems;

	return *this;
}

bool Triangular::next(int& val) const
{
	if (_next < _beg_pos + _length - 1)
	{
		val = _elems[_next++];
		return true;
	}
	return false;
}


bool Triangular::is_elem(int value)
{
	if (!_elems.size() || _elems[_elems.size() - 1] < value)
		gen_elems_to_value(value);

	vector<int>::iterator found_it;
	vector<int>::iterator end_it = _elems.end();

	found_it = find(_elems.begin(), end_it, value);
	return found_it != end_it;
}

void Triangular::gen_elements(int length)
{
	if (length < 0 || length > _max_elems)
	{
		cerr << "invalid input!" << endl;
		return;
	}

	if (_elems.size() < (unsigned)length)
	{
		int ix = _elems.size() ? _elems.size() + 1 : 1;
		for (; ix <= length - 1; ++ix)
			_elems.push_back(ix * (ix + 1) / 2);
	}
}

void Triangular::gen_elems_to_value(int value)
{
	int ix = _elems.size();
	if (!ix)
	{
		_elems.push_back(1);
		ix = 1;
	}
	while (_elems[ix - 1] < value && ix < _max_elems)
	{
		_elems.push_back(ix * (ix + 1) / 2);
		++ix;
	}
	if (ix == _max_elems)
		cerr << "invaild input" << endl;
}

void Triangular::display(int len, int beg_pos, ostream& os)
{
	Triangular tri(len, beg_pos);
	os << "(" << len << "," << beg_pos << ")" << ' ';
	Triangular::iterator it = tri.begin();
	Triangular::iterator end_it = tri.end();

	while (it != end_it)
	{
		os << *it << ' ';
		++it;
	}
	os << endl;

}
//

int sum(const Triangular& trian)
{
	if (!trian.length())
		return 0;
	int val, sum = 0;
	trian.next_reset();
	while (trian.next(val))
		sum += val;
	return sum;
}

ostream& operator<<(ostream& os, const Triangular& rhs)
{
	rhs.display(rhs.length(), rhs.beg_pos(), os);
	return os;
}

istream& operator>>(istream& is, Triangular& rhs)
{
	char ch1, ch2;
	int bp, len;

	is >> ch1 >> len >> ch2 >> bp;

	rhs.beg_pos(bp);
	rhs.length(len);
	rhs.next_reset();

	return is;
}