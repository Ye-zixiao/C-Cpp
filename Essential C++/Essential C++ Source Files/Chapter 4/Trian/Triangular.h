//triangular.h

#ifndef TRIANGULAR_H_INCLUDED
#define TRIANGULAR_H_INCLUDED

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class iterator_overflow {//第七章的内容..抛出异常..
public:
	iterator_overflow(int index, int max)
		:_index(index), _max(max) {}

	int index() { return _index; }
	int max() { return _max; }

	void what_happended(ostream& os = cerr)
	{
		os << "Internal error";
	}

private:
	int _index;
	int _max;

};

class Triangular_iterator {

	friend class Triangular;

public:
	Triangular_iterator(int index) : _index(index - 1) {}

	bool operator==(const Triangular_iterator&) const;
	bool operator!=(const Triangular_iterator&) const;
	int operator*() const;
	Triangular_iterator& operator++();
	Triangular_iterator operator++(int);

private:
	void check_integrity() const;
	int _index;
};

class Triangular {

	friend int Triangular_iterator::operator*() const;
	friend void Triangular_iterator::check_integrity() const;

public:
	Triangular(int len = 1, int beg_pos = 1);

	int length() const { return _length; }
	int beg_pos() const { return _beg_pos; }
	void beg_pos(int bp) { _beg_pos = bp; }
	void length(int len) { _length = len; }
	int elem(int pos) const { return _elems[pos - 1]; }

	Triangular& copy(const Triangular& rhs);

	bool next(int&) const;
	void next_reset() const { _next = _beg_pos - 1; }

	typedef Triangular_iterator iterator;
	Triangular_iterator begin() const { return Triangular_iterator(_beg_pos); }
	Triangular_iterator end() const { return Triangular_iterator(_beg_pos + _length); }

	static bool is_elem(int);
	static void gen_elements(int length);
	static void gen_elems_to_value(int value);
	static void display(int len, int beg_pos, ostream& os = cout);

private:
	int _length;
	int _beg_pos;
	mutable int _next;
	static const int _max_elems = 25;
	static vector<int> _elems;
};

int sum(const Triangular&);

ostream& operator<<(ostream&, const Triangular&);

istream& operator>>(istream&, Triangular&);


inline bool Triangular_iterator::
operator==(const Triangular_iterator& rhs) const
{
	return _index == rhs._index;
}

inline bool Triangular_iterator::
operator!=(const Triangular_iterator& rhs) const
{
	return !(*this == rhs);
}

inline int Triangular_iterator::
operator*() const
{
	check_integrity();
	return Triangular::_elems[_index];
}

inline void Triangular_iterator::
check_integrity() const
{
	if (_index >= Triangular::_max_elems)
		cerr << "Error!" << endl;
		//throw iterator_overflow(_index, Triangular::_max_elems);
	if ((unsigned)_index >= Triangular::_elems.size())
		Triangular::gen_elements(_index + 1);
}

inline Triangular_iterator& Triangular_iterator::
operator++()
{
	++_index;
	check_integrity();
	return *this;
}

inline Triangular_iterator Triangular_iterator::
operator++(int)
{
	Triangular_iterator tmp = *this;
	++_index;
	check_integrity();
	return tmp;
}

#endif // TRIANGULAR_H_INCLUDED