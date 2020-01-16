#include<iostream>
#include<vector>
using namespace std;

void show_seq(const vector<int> *seq);
const vector<int>* fibo_seq(int size);

int main(void)
{
	int size;
	cout << "Enter the seq_number of fibonacci: ";
	cin >> size;

	const vector<int>* pseq = 0;
	pseq = fibo_seq(size);
	if (pseq)
		show_seq(pseq);

	return 0;
}

void show_seq(const vector<int>* seq)
{
	for (int i = 0; i < (*seq).size(); i++)		//对类对象进行解引用，必须要将类对象解引用之后再用括号括起来。
		cout << (*seq)[i] << " ";				/*这个跟C中的指向结构的指针的解引用是相同的，只不过是因为C++中的vector对他的
												容器访问不能像访问方法一样用“->”的运算符
												最根本原因："."运算符的优先级高于“->“运算符的优先级*/
	cout << endl;
}

const vector<int>* fibo_seq(int size)
{
	const int max_size = 1024;
	static vector<int> elems;				//使用函数作用域的静态vector类对象，在整个函数运行过程中都不会被释放

	if (size<0 || size>max_size)
	{
		cerr << "invalid size" << endl;
		return 0;
	}

	for (int i = elems.size(); i < size; i++)
	{
		if (0 == i || i == 1)
			elems.push_back(1);
		else
			elems.push_back(elems[i - 1] + elems[i - 2]);
	}

	return &elems;
}
