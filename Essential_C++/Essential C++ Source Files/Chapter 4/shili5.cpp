#include<iostream>
#include<vector>
using namespace std;

class num_sequence
{
public://公开接口
	typedef void (num_sequence::*PtrType)(int);	//声明了一个成员函数指针

	void fibonacci(int pos);					//以下数列算法，计算出具体数列的值然后将其存放到静态成员变量vector之中
	void pell(int pos);
	void lucas(int pos);
	void triangular(int pos);
	void sequare(int pos);
	void pentagonal(int pos);

	int elem(int pos);							//返回数列的某一个位置上的值
	bool check_integrity(int pos);              //检查位置是否在数列中有效

private:
	vector<int>* _elem;							//存放包含指向含有具体数列的vector向量的指针
	PtrType _pmf;
	static const int num_seq = 7;
	static PtrType func_tbl[num_seq];
	static vector<vector<int> > seq;
};

/*对于静态变量，必须为其在类外分配时间*/
const int num_sequence::num_seq;
vector<vector<int> > num_sequence::seq(num_seq);

num_sequence::PtrType num_sequence::func_tbl[num_seq] =	/*1、由于PtrType是num_sequence类的嵌套类型，所以在类外对类成员函数指针
														进行访问时，必须在其前面加上类作用域运算符加以限制。
														  2、而后面的num_sequence::func_tbl[num_seq]前面加上num_sequence::与之不同，
														其目的是为了表明该静态成员变量（数据）是属于哪一个类的*/
{
	0,
	&num_sequence::fibonacci,
	&num_sequence::pell,
	&num_sequence::lucas,
	&num_sequence::triangular,
	&num_sequence::pentagonal,
	&num_sequence::sequare,
};


int main(void)
{
	num_sequence ns;
	num_sequence* pns = &ns;
	num_sequence::PtrType pm = &num_sequence::fibonacci;
	int pos = 9;
	(ns.*pm)(pos);			/*成员函数指针的解引用当成员函数使用时没有像普通函数指针那样的两种用法（形式）：1解引用式，
								2函数指针函数相等式（这是由于历史原因造成的）*/
	(pns->*pm)(pos);


	return 0;
}

int num_sequence::
elem(int pos)
{
	if (!check_integrity(pos))
		return 0;
	if (pos > _elem->size())
		(this->*_pmf)(pos);

	return (*_elem)[pos - 1];
}
