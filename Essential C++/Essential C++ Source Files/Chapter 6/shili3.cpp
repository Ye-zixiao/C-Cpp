#include<iostream>
#include<vector>
#include<typeinfo>
using namespace std;

template<int len,int beg_pos>
class num_sequence
{
public:
	num_sequence() {}
	virtual ~num_sequence() {};

	virtual int elem(int pos) const = 0;
	const char* who_am_i() const
	{
		return typeid(*this).name();
	}
	static int max_elems() { return _max_elems; }
	virtual ostream& print(ostream& os) const = 0;

protected:
	virtual void gen_elems(int pos) const = 0;
	bool check_integrity(int pos,int size) const;
	static const int _max_elems = 1024;
};

template<int len,int beg_pos>
ostream& operator<<(ostream& os, const num_sequence<len, beg_pos>& ns)
{
	return ns.print(os);
}

template<int len,int beg_pos=1>
class Norm_num :public num_sequence<len, beg_pos>
{
public:
	Norm_num(){}
	virtual ~Norm_num(){}

	virtual int elem(int pos) const;
	virtual ostream& print(ostream& os) const;

protected:
	virtual void gen_elems(int pos) const;
	static vector<int> _elems;
};


/*------------------¿‡∂®“Â-------------------*/
template<int len,int beg_pos>
bool num_sequence<len,beg_pos>::
check_integrity(int pos, int size) const
{
	if (pos<0 || pos>max_elems())
		return false;
	if (pos > size)
		gen_elems(pos);
	return true;
}

template<int len,int beg_pos>
int Norm_num<len,beg_pos>::
elem(int pos) const
{
	if(!num_sequence<len,beg_pos>::check_integrity(pos,_elems.size()))
		return 0;
	return (*this)._elems[pos-1];
}

template<int len,int beg_pos>
ostream& Norm_num<len,beg_pos>::
print(ostream& os) const
{
	int begin_index = beg_pos - 1;
	int end_index = begin_index + len;

	if (_elems.empty())
		gen_elems(end_index);

	os << num_sequence<len,beg_pos>::who_am_i() << "(" << beg_pos << ","
		<< end_index << ")" << ": ";
	for (; begin_index <= end_index; ++begin_index)
		os << _elems[begin_index] << " ";

	return os;
}

template<int len,int beg_pos>
void Norm_num<len,beg_pos>::
gen_elems(int pos) const
{
	if (!num_sequence<len,beg_pos>::check_integrity(pos, _elems.size()))
		return;
	int index = _elems.size();
	for (; index <= pos; ++index)
		_elems.push_back(index + 1);
}

template<int len,int beg_pos>
vector<int> Norm_num<len, beg_pos>::_elems;

int main(void)
{
	Norm_num<1, 10> nt1;
	cout << nt1 << endl;

	return 0;
}
