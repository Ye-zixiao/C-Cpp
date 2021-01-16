#include<iostream>
#include<vector>
#include<string>
#include<typeinfo>
using namespace std;

class num_sequence
{
public:
	num_sequence(int len, int begin_pos);
	virtual ~num_sequence() {}

	virtual int elem(int pos) const = 0;
	virtual const char* who_am_i() const = 0;
	virtual ostream& print(ostream& os = cout) const = 0;
	int length() const { return _length; }
	int begin_pos() const { return _begin_pos; }

protected:
	virtual void gen_elems(int pos) const = 0;
	bool check_integrity(int pos, int size) const;
	int _length;
	int _begin_pos;

};

inline num_sequence::
num_sequence(int len, int begin_pos)
	:_length(len), _begin_pos(begin_pos) {}

bool num_sequence::
check_integrity(int pos, int size) const
{
	if (pos < 0 || pos>20)
		return false;
	if (pos > size)
		gen_elems(pos);
	return true;
}

ostream& operator<<(ostream& os, num_sequence& ns)
{
	return ns.print(os);
}
/*===========================*/
class Norm_num :public num_sequence
{
public:
	Norm_num(int len = 0, int begin_pos = 0)
		:num_sequence(len, begin_pos) {}
	virtual ~Norm_num() {}

	virtual int elem(int pos) const;
	virtual const char* who_am_i() const
	{
		return typeid(*this).name();
	}
	virtual ostream& print(ostream& os=cout) const;

protected:
	static vector<int> _elems;
	virtual void gen_elems(int pos) const;
	virtual bool check_integrity(int pos) const;

};

int Norm_num::
elem(int pos) const
{
	if (!check_integrity(pos))
		return 0;
	return _elems[pos - 1];
}

ostream& Norm_num::
print(ostream& os) const
{
	int i = _begin_pos;
	int j = i + _length;
	if (j > _elems.size())
		gen_elems(j);
	for (; i < j; ++i)
		os << _elems[i] << ' ';
	os << endl;
	os << _elems.size() << endl;
	return os;
}

void Norm_num::
gen_elems(int pos) const
{
	int i = _elems.size();
	for (; i < pos; i++)
	{
		_elems.push_back(i + 1);
	}
}

bool Norm_num::
check_integrity(int pos) const
{
	if (!num_sequence::check_integrity(pos, _elems.size()))
		return false;
	else
		return true;
}

vector<int> Norm_num::_elems;

int main(void)
{
	Norm_num ns(10,3);
	cout << ns << endl;
	cout << ns.who_am_i() << endl;


	return 0;
}
