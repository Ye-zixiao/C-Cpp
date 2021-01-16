#include<iostream>
#include<vector>
using namespace std;

class num_sequence						//�������
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


class Fibonacci :public num_sequence	//������
{

public:
	Fibonacci(int len = 1, int begin_pos = 1)
		:_length(len), _begin_pos(begin_pos) {}

	virtual int elem(int pos) const;						//ÿһ�����������Ի���Ĵ��麯����������������������
	virtual const char* what_am_i() const { return "Fibonacci"; }
	virtual ostream& print(ostream& os = cout) const;
	int length() const { return _length; }					//�����ڻ���������Ϊ������
	int begin_pos() const { return _begin_pos; }

protected:
	virtual void gen_elems(int pos) const;//���const��������ڣ�
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
	ostream& print(ostream& os = cout) const;//����������������Ϊ�˸��ǻ���Ĵ��麯��ʱ����һ������ǰ����Ϲؼ���virtual
	int length() const { return _length; }
	int begin_pos() const { return _begin_pos; }

protected:
	virtual void gen_elems(int pos) const;
	bool check_integrity(int pos) const;
	int _length;
	int _begin_pos;
	static vector<int> _elems;

};

/*-------------����ĳ�Ա����---------------*/
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
		gen_elems(pos);//ʹ��������ƣ�ֻ�е�ָ������ָ��������ڳ���ִ��ǰ����һ�̲Ż�ȷ�����׻������һ����ĺ���

	return true;
}

ostream& operator<<(ostream& os, const num_sequence& ns)
{
	return ns.print(os);
}


/*-----------------Fibonacci������ĳ�Ա����--------------*/
int Fibonacci::
elem(int pos) const
{
	if (!num_sequence::check_integrity(pos, _elems.size()))
		return 0;
	if ((unsigned)pos > _elems.size())
		//Fibonacci::gen_elems(pos);
										/*�������������������߱��������ú�����Ҫ���õĺ�����������һ������ʵ����
										���ֻ����������麯������*/
		gen_elems(pos);					//���ַ����������麯���Ļ��ƣ�ֻ�е�����ʱ�̲���֪���Լ���Ҫ�����ĸ������Ӧ��Ա����

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

		for (; index < pos; ++index)			//���index<=pos�Ļ����ͻ������һ��
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
		Fibonacci::gen_elems(end_pos);	//�����������
		//gen_elems(end_pos);			//�����������
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


/*-----------------Triangular������ĳ�Ա����------------------*/
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
		Triangular::gen_elems(end_pos);	//�����������
		//gen_elems(end_pos);			//�����������
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
