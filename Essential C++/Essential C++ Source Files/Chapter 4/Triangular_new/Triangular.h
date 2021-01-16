#ifndef TRIANGULAR_H_
#define TRIANGULAR_H_

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Triangular_iterator											//程序的成功运行还与类定义的先后顺序有关
{
public:
	Triangular_iterator(int index) :_index(index - 1) {}

	bool operator==(const Triangular_iterator&) const;
	bool operator!=(const Triangular_iterator&) const;
	int operator*() const;
	Triangular_iterator& operator++();
	Triangular_iterator operator++(int);

private:
	void check_integrity() const;
	int _index;

};

class Triangular
{
	/*friend int Triangular_iterator::operator*() const;
	friend void Triangular_iterator::check_integrity() const;*/
	friend class Triangular_iterator;								//Triangular_iterator只有当先定义的情况下才能正确编译
																	//Triangular_iterator的所有成员函数都成为了Triangulars的友元
public:
	Triangular(int len = 1, int bp = 1);
	Triangular& operator=(const Triangular& rhs);					//拷贝赋值运算符重载，用于类对象到类对象实例的复制
	
	int length() const { return _length; }
	void length(int len) { _length = len; }
	void begin_pos(int bp) { _begin_pos = bp; }
	int begin_pos() const { return _begin_pos; }
	void next_reset() const { _next = _begin_pos - 1; }
	void display(int length, int begin_pos, ostream& os) const;

	typedef Triangular_iterator iterator;							/*将iterator嵌套在每一个“提供iterator抽象概念”的class内，我们就可以
																		提供有者相同名称的多个定义*/
	Triangular_iterator begin() const
	{
		return Triangular_iterator(_begin_pos);						//返回首部索引
	}
	Triangular_iterator end() const
	{
		return Triangular_iterator(_begin_pos + _length);			//返回尾部索引
	}

	static bool is_elem(int value);
	static void gen_elements(int length);
	static void gen_elems_to_value(int value);
	
private:
	static const int _max_elems = 25;
	static vector<int> _elems;
	int _length;						//数列长度
	int _begin_pos;						//数列开始下标，不一定是1，可以根据用户设置
	mutable int _next;
};

ostream& operator<<(ostream& os, const Triangular& rhs);			//使用重载输出运算符达到直接输出类对象中的数据的目的
istream& operator>>(istream& is, Triangular& rhs);					//使用重载输入运算符达到直接将数据输入到类对象中的目的

/*====================Triangular的迭代器类的内联函数========================*/
inline bool Triangular_iterator::
operator==(const Triangular_iterator &rhs) const					//判断当前两个迭代器（的索引）是否相同
{
	return _index == rhs._index;
}

inline bool Triangular_iterator::
operator!=(const Triangular_iterator& rhs) const					//判断当前两个迭代器是否不相同
{
	return !(*this == rhs);
}

inline int Triangular_iterator::									//对Triangular迭代器进行解引用，同时会检查迭代器的索引是否正确
operator*() const
{
	check_integrity();
	return Triangular::_elems[_index];/*这个类作用域解析运算符是必需要加的。为什么？？
									  是因为当前的成员函数是属于迭代器类的，而不是triangular类的，
									  所以访问triangular中的_elems静态成员数据需要在当前Triangular_iterator成员函数中
									  指出这个数据是在哪里的（同时这也是访问静态成员数据的规定！！！）*/
}

inline void Triangular_iterator::
check_integrity() const												//对迭代器的索引进行安全性检查
{
	if ((unsigned)_index == Triangular::_max_elems)
		cerr << "Error!" << endl;
	
	if ((unsigned)_index >= Triangular::_elems.size())				/*如果迭代器的索引正常，但静态变量vector没有这么多的数据，
																		就需要调用Triangular中的成员函数去生成要求数量的数据*/
		Triangular::gen_elements(_index + 1);
}

inline Triangular_iterator& Triangular_iterator::
operator++()														//迭代器自增函数（前缀版本）
{
	++_index;
	check_integrity();
	return *this;
}

inline Triangular_iterator Triangular_iterator::
operator++(int)														//迭代器自增函数（后缀版本）
{
	Triangular_iterator tmp = *this;
	check_integrity();
	return tmp;
}

#endif