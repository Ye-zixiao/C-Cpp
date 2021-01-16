/*-----------------------------非类型模板参数-------------------------------*/
#include<iostream>
#include<vector>
#include<typeinfo>
using namespace std;

template<int len, int beg_pos>								//使用非类型模板参数的基类
class num_sequence
{
public:
	num_sequence() {}
	virtual ~num_sequence() {};

	virtual int elem(int pos) const = 0;
	virtual ostream& print(ostream& os) const = 0;

	const char* who_am_i() const
	{
		return typeid(*this).name();
	}
	static int max_elems() { return _max_elems; }
	void hello_world();

protected:
	virtual void gen_elems(int pos) const = 0;
	bool check_integrity(int pos, int size) const;
	static const int _max_elems = 1024;
};

template<int len, int beg_pos>
ostream& operator<<(ostream& os, const num_sequence<len, beg_pos>& ns)//输出运算符重载
{
	return ns.print(os);
}


template<int len, int beg_pos = 1>								//使用非类型模板参数的派生类
class Norm_num :public num_sequence<len, beg_pos>
{
public:
	Norm_num() {
		//cout << beg_pos << endl;
		gen_elems(beg_pos - 1 + len);						/*为了防止需要访问vector中的数据时，才去生成相应的相应的vector向量数据而导致的一
															系列问题的这种现象。最好的解决方法就是在一开始执行构造函数的时候就生成vector向量
															将其存储到vector中*/
	}
	virtual ~Norm_num() {}

	virtual int elem(int pos) const;
	virtual ostream& print(ostream& os) const;
	void hello();

protected:
	virtual void gen_elems(int pos) const;
	static vector<int> _elems;
};


/*------------------基类成员函数定义-------------------*/
template<int len, int beg_pos>
bool num_sequence<len, beg_pos>::
check_integrity(int pos, int size) const
{
	if (pos < 0 || pos>1024)
		return false;
	if (pos > size)
		gen_elems(pos);
	return true;
}

template<int len, int beg_pos>
void num_sequence<len, beg_pos>::
hello_world()
{
	cout << "hello world!" << endl;
}


/*------------------派生类成员函数定义-------------------*/
template<int len, int beg_pos>
int Norm_num<len, beg_pos>::
elem(int pos) const
{
	if (!num_sequence<len, beg_pos>::check_integrity(pos, _elems.size()))
		//if(!this->check_integrity(pos,_elems.size()))						//解决方法的其中一个就是使用this指针解引用
		return 0;														/*为什么派生类中的成员函数调用基类中的非虚拟函数需要在前面指定类作用域解析运算符？
																		这种问题我的解释是派生类在以多态的特性（基类的引用/指针实际上指向的是派生类）的方式
																		调用任何函数时，都会认为所调用的函数都是该派生类自身的那份成员函数，而不会认为该函数是
																		来自于基类的成员函数。
																			或者说派生类调用基类的成员函数都需要使用到类作用域解析运算符？？*/
	return _elems[pos - 1];
}

template<int len, int beg_pos>
ostream& Norm_num<len, beg_pos>::
print(ostream& os) const
{
	int begin_index = beg_pos - 1;
	//cout << begin_index << endl;
	int end_index = begin_index + len;

	if (_elems.empty() || end_index > _elems.size())				//检查向量是否为空或者向量中的数据是否满足要求的长度
		gen_elems(end_index);

	os << num_sequence<len, beg_pos>::who_am_i() << ": ";
	for (; begin_index < end_index; ++begin_index)
		os << _elems[begin_index] << " ";

	return os;
}

template<int len, int beg_pos>
void Norm_num<len, beg_pos>::
gen_elems(int pos) const
{
	if (pos <= 0 || pos > num_sequence<len, beg_pos>::max_elems())
		return;

	int index = _elems.size();
	for (; index < pos; ++index)
	{
		cout << "add " << (index + 1) << endl;
		_elems.push_back(index + 1);

	}
}

template<int len, int beg_pos>
void Norm_num<len, beg_pos>::
hello()
{
	cout << num_sequence<len, beg_pos>::who_am_i() << endl;			//采用类作用域解析运算符直接调用，调用时会让人感觉认为这个基类函数像是在处理派生类自身的一样
	cout << this->who_am_i() << endl;								//依托于类对象，这种方式很继承特性，直接认为在调用自身的函数
	this->hello_world();											//解决方法1：使用this指针->解引用。这种方法和先解引用this指针一个道理
	(*this).hello_world();
	num_sequence<len, beg_pos>::hello_world();						//解决方法2：使用类作用域解析运算符限定使用的是哪一个类中的函数

	//using num_sequence<len,beg_pos>::hello_world;
	//hello_world();

}


template<int len, int beg_pos>
vector<int> Norm_num<len, beg_pos>::_elems;

/*--------------------主调函数-----------------*/
int main(void)
{
	Norm_num<10> nt1;
	cout << nt1.elem(2) << endl;
	cout << nt1 << endl;
	nt1.hello();

	Norm_num<10, 4> nt2;
	cout << nt2 << endl;

	cout << nt2.max_elems() << endl;

	return 0;
}

/*
#include<iostream>
using namespace std;

class one
{
public:
	void hello()
	{
		cout << "hello world!" << endl;
	}


};

class two :public one
{
public:
	void fuck();					//在不是非类型模板参数的类中是可以调用基类中的成员函数的！所以我认为上面的问题就是出在
									//模板参数的引入。

};

void two::
fuck()
{
	hello();
}

int main(void)
{
	two newnew;
	newnew.fuck();

	return 0;
}
*/