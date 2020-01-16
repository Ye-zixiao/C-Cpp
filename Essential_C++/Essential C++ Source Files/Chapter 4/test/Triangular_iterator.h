//Triangular_iterator.h
#ifndef TRIANGULAR_ITERATOR_H
#define TRIANGULAR_ITERATOR_H
#include<vector>
using namespace std;

class Triangular_iterator {
	//friend int operator*(const Triangular_iterator &rhs);
public:
	//friend class Triangular;
	Triangular_iterator(int index) :_index(index - 1) {}
	//Triangular_iterator(const int &rhs) :_index(rhs) {}
	bool operator==(const Triangular_iterator&)const;
	bool operator!=(const Triangular_iterator&)const;
	int operator*()const;

	Triangular_iterator & operator++();
	Triangular_iterator operator++(int);
private:
	void check_inteqrity()const;
	size_t _index;
};

class Triangular {

	//friend int operator*(const Triangular_iterator &rhs);
public:
	friend int Triangular_iterator::operator*()const;
	friend void Triangular_iterator::check_inteqrity() const;

	//friend class Triangular_iterator;

	typedef Triangular_iterator iterator;
	Triangular() { _length = 1; _beg_pos = 1; _elems.push_back(1); }
	Triangular(int len, int beg_pos = 1);
	void gen_elems();
	int length() { return _length; }
	//int begin() { return 0; }
	//int end() { return _length - 1; }
	static int elem_size() { return _elems.size(); }
	static int max_elems() { return _max_elems; }
	Triangular_iterator begin() const { return Triangular_iterator(_beg_pos); }
	Triangular_iterator end() const { return Triangular_iterator(_beg_pos + _length); }

	//int sum(const Triangular &trian);
	int length()const { return _length; }
	int beg_pos()const { return _beg_pos; }
	bool next(int &val) const;
	void next_reset()const { _next = _beg_pos - 1; }//void next_reset() const { _next = _beg_pos - 1; }
	static bool is_elem(int value);           //Static means this function does not depend on whether the class is instantiated to an object or not.
	static void gen_elements(int length);
	static void gen_elems_to_value(int value);
	//   static void display( int len, int beg_pos, ostream &os = cout );
	// ...
private:
	mutable int _next;
	int _length;
	int _beg_pos;
	static const int   _max_elems = 100;       //Not allowed in VC.
	static vector<int> _elems;
	// ...
};

#endif // !TRIANGULAR_ITERATOR_H
