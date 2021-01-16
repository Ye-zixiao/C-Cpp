#include<iostream>
#include<vector>
using namespace std;

class num_sequence						//抽象基类
{

public:
	virtual ~num_sequence();

	virtual int elem(int pos) const = 0;
	virtual const char* what_am_i() const = 0;
	static int max_elems() { return _max_elems; }
	virtual ostream& print(ostream& os = cout) const = 0;

protected:
	virtual void gen_elems(int pos) const = 0;
	bool check_integrity(int pos, int size) const;

	const static int _max_elems = 1024;
};


class Fibonacci :public num_sequence	//派生类
{

public:
	Fibonacci(int len = 1, int begin_pos = 1)
		:_length(len), _begin_pos(begin_pos) {}

	virtual int elem(int pos) const;						//每一个派生类必须对基类的纯虚函数进行重新声明，并定义
	virtual const char* what_am_i() const { return "Fibonacci"; }
	virtual ostream& print(ostream& os = cout) const;
	int length() const { return _length; }					//可以在基类中设置为纯虚数
	int begin_pos() const { return _begin_pos; }

protected:
	virtual void gen_elems(int pos) const;//这个const的意义何在？
	bool check_integrity(int pos) const;
	int _length;
	int _begin_pos;
	static vector<int> _elems;
};


class Triangular :public num_sequence
{
public:
	Triangular(int len=1,int begin_pos=1)
		:_length(len),_begin_pos(begin_pos){}

	virtual int elem(int pos) const;
	virtual const char* what_am_i() const { return "Triangular"; }
	ostream& print(ostream& os = cout) const;//当我们在派生类中为了覆盖基类的纯虚函数时，不一定得在前面加上关键字virtual
	int length() const { return _length; }
	int begin_pos() const { return _begin_pos; }

protected:
	virtual void gen_elems(int pos) const;
	bool check_integrity(int pos) const;
	int _length;
	int _begin_pos;
	static vector<int> _elems;

};

/*-------------基类的成员函数---------------*/
inline num_sequence::
~num_sequence() {}

bool num_sequence::
check_integrity(int pos, int size) const
{
	if (pos <= 0 || pos > _max_elems)
	{
		cerr << "!!invalid position: " << pos
			<< " Cannot honor request\n";
		return false;
	}
	if (pos > size)
		gen_elems(pos);//使用虚拟机制，只有当指向基类的指针或引用在程序执行前的那一刻才会确定到底会调用哪一个类的函数

	return true;
}

ostream& operator<<(ostream& os, const num_sequence& ns)
{
	return ns.print(os);
}


/*-----------------Fibonacci派生类的成员函数--------------*/
int Fibonacci::
elem(int pos) const
{
	if (!num_sequence::check_integrity(pos, _elems.size()))
		return 0;
	if ((unsigned)pos > _elems.size())
		//Fibonacci::gen_elems(pos);
										/*类作用域解析运算符告诉编译器，该函数想要调用的函数到底是哪一个函数实例。
										这种机制跳过了虚函数机制*/
		gen_elems(pos);					//这种方法采用了虚函数的机制，只有当运行时刻才能知道自己需要调用哪个类的相应成员函数

	return _elems[pos - 1];
}

void Fibonacci::
gen_elems(int pos) const
{
	if (_elems.empty())
	{
		_elems.push_back(1);
		_elems.push_back(1);
	}
	if (_elems.size() < (unsigned)pos)
	{
		int index = _elems.size();
		int n_2 = _elems[index - 2];
		int n_1 = _elems[index - 1];

		for (; index < pos; ++index)			//如果index<=pos的话，就会多生产一个
		{
			int elem = n_1 + n_2;
			cout << "gen_elems: " << elem << endl;
			_elems.push_back(elem);
			n_2 = n_1;
			n_1 = elem;
		}
		cout << _elems.size() << endl;
	}
}

ostream& Fibonacci::
print(ostream& os) const
{
	int elem_pos = _begin_pos - 1;
	int end_pos = elem_pos + _length;

	if ((unsigned)end_pos > _elems.size())
		Fibonacci::gen_elems(end_pos);	//跳过虚拟机制
		//gen_elems(end_pos);			//采用虚拟机制
	while (elem_pos < end_pos)
		os << _elems[elem_pos++] << ' ';

	return os;
}

inline bool Fibonacci::
check_integrity(int pos) const
{
	if (!num_sequence::check_integrity(pos, _elems.size()))
		return false;

	if ((unsigned)pos > _elems.size())
		Fibonacci::gen_elems(pos);

	return true;
}


/*-----------------Triangular派生类的成员函数------------------*/
bool Triangular::
check_integrity(int pos) const
{
	if (!num_sequence::check_integrity(pos, _elems.size()))
		return false;
	if ((unsigned)pos > _elems.size())
		Triangular::gen_elems(pos);
	return true;
}

int Triangular::
elem(int pos) const
{
	if(!num_sequence::check_integrity(pos,_elems.size()))
		return 0;
	if ((unsigned)pos > _elems.size())
		Triangular::gen_elems(pos);

	return _elems[pos - 1];
}

void Triangular::
gen_elems(int pos) const
{
	if (_elems.empty())
		_elems.push_back(1);
	if ((unsigned)pos > _elems.size())
	{
		int index = _elems.size();
		for (; pos > index; ++index)
		{
			cout << "generate value: " << (index + 1) * (index + 2) / 2 << endl;
			_elems.push_back((index + 1)*(index + 2) / 2);
		}
	}
	cout << _elems.size() << endl;
}

ostream& Triangular::
print(ostream& os) const
{
	int elem_pos = _begin_pos - 1;
	int end_pos = elem_pos + _length;

	if ((unsigned)end_pos > _elems.size())
		Triangular::gen_elems(end_pos);	//跳过虚拟机制
		//gen_elems(end_pos);			//采用虚拟机制
	while (elem_pos < end_pos)
		os << _elems[elem_pos++] << ' ';

	return os;
}

vector<int> Fibonacci::_elems;
vector<int> Triangular::_elems;

int main(void)
{
	//Fibonacci fib;

	//cout << "fib: beginning at element 1 for 1 element: \n"
	//	<< fib << endl;
	//cout << endl;

	//Fibonacci fib2(16);
	//cout << "fib2: beginning at element 1 for 16 elements: \n"
	//	<< fib2 << endl;
	//cout << endl;

	//Fibonacci fib3(8, 12);
	//cout << "fib3: beginning at element 12 for 8 elements: \n"
	//	<< fib3 << endl;
	//cout << endl;

	Triangular tri0(10, 1);

	cout << tri0 << endl;
	cout << endl;

	Triangular tri1(10, 3);

	cout << tri1 << endl;
	cout << endl;

	return 0;
}
