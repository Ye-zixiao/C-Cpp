#include<iostream>
#include<string>
#include<vector>
using namespace std;

template<typename elemType>
class example
{
public:
	example(elemType min, elemType max);					//构造2个元素的数组
	example(const elemType* array, int size);				//构造一个长度为size的数组
	~example() {
		cout << "deconstructor" << endl;
		delete []parray;
		cout << "end?" << endl;
	}

	elemType operator[](int index);						//重载运算符
	bool operator=(const example&);
	bool insert(const elemType*, int length);				//插入一个长度为length的数组
	bool insert(elemType);									//插入一个元素
	elemType min() const { return _min; }
	elemType max() const { return _max; }
	void min(elemType);										//重新设置最小/大值
	void max(elemType);
	int count(elemType value);								//计数
	void print(void) const;

private:
	int _size;
	elemType* parray;
	elemType _min;
	elemType _max;
};

/*----------模板类成员函数的定义------------------------*/
template<typename elemType>
void example<elemType>::
print(void) const
{
	for (int i = 0; i < _size; ++i)
		cout << parray[i] << ' ';
	cout << endl;
}

template<typename elemType>
example<elemType>::
example(elemType min, elemType max)
	:_max(max), _min(min), _size(2)
{
	parray = new elemType[_size];
	if (!parray)
		cerr << "Error" << endl;
	parray[0] = min;
	parray[1] = max;
}

template<typename elemType>
example<elemType>::
example(const elemType* array, int size)
{
	_size = size;
	parray = new elemType[size];
	if (!parray)
		cerr << "Error" << endl;

	elemType min, max;
	parray[0] = array[0];
	min = array[0];
	max = array[0];
	for (int i = 1; i < size; ++i)
	{
		parray[i] = array[i];
		if (array[i] > max)
			max = array[i];
		if (array[i] < min)
			min = array[i];
	}
	_min = min;
	_max = max;
}

template<typename elemType>
elemType example<elemType>::
operator[](int index)
{
	if (index<0 || index>_size)
	{
		cerr << "Error" << endl;
		return 0;
	}
	return parray[index];
}

template<typename elemType>
bool example<elemType>::
operator=(const example& ex)
{
	_size = ex._size;
	elemType* ptemp = parray;
	parray = new elemType[_size];
	if (!parray)
	{
		cerr << "Error" << endl;
		return false;
	}

	elemType min, max;
	parray[0] = ex.parray[0];
	min = parray[0];
	max = parray[0];
	for (int i = 1; i < _size; ++i)
	{
		parray[i] = ex.parray[i];
		if (min > parray[i])
			min = parray[i];
		if (max < parray[i])
			max = parray[i];
	}
	_min = min;
	_max = max;

	delete []ptemp;
	return true;
}

template<typename elemType>
bool example<elemType>::
insert(const elemType* array, int length)
{
	elemType* ptemp = new elemType[_size + length];
	if (!ptemp)
	{
		cerr << "Error" << endl;
		return false;
	}

	for (int i = 0; i < _size; ++i)
		ptemp[i] = parray[i];
	elemType min = _min;
	elemType max = _max;

	for (int i = _size; i < _size + length; ++i)
	{
		ptemp[i] = array[i - _size];
		if (min > ptemp[i])
			min = ptemp[i];
		if (max < ptemp[i])
			max = ptemp[i];
	}
	_min = min;
	_max = max;
	_size += length;
	elemType* ptemp1 = parray;
	parray = ptemp;

	delete []ptemp1;
	return true;
}

template<typename elemType>
bool example<elemType>::
insert(elemType val)
{
	if (_min > val)
		_min = val;
	if (_max < val)
		_max = val;
	elemType* ptemp = new elemType[_size + 1];
	if (!ptemp)
	{
		cout << "Error" << endl;
		return false;
	}

	for (int i = 0; i < _size; ++i)
	{
		if (i != _size - 1)
			ptemp[i] = parray[i];
		if (i == _size - 1)
			ptemp[i] = val;
	}

	elemType* ptemp1 = parray;
	parray = ptemp;
	delete []ptemp1;
	return true;
}

template<typename elemType>
void example<elemType>::
min(elemType min)
{
	for (int i = 0; i < _size; ++i)
	{
		if (parray[i] < min)
			parray[i] = min;
	}
	_min = min;
}

template<typename elemType>
void example<elemType>::
max(elemType max)
{
	for (int i = 0; i < _size; ++i)
	{
		if (parray[i] > max)
			parray[i] = max;
	}
	_max = max;
}

template<typename elemType>
int example<elemType>::
count(elemType val)
{
	int count = 0;
	for (int i = 0; i < _size; ++i)
		if (val == parray[i])
			++count;
	return count;
}

int main(void)
{
	int array[10];
	for (int i = 0; i < 10; ++i)
		array[i] = i + 1;

	int* parray_temp = array;
	example<int> ex(parray_temp, 10);
	cout << ex.min() << endl;
	cout << ex.max() << endl;
	if (ex.insert(12))
		cout << ex.max() << endl;

	int fortest[10];
	for (int i = 0; i < 10; ++i)
		fortest[i] = 20 + i;
	int* pfortest = fortest;

	if (ex.insert(pfortest, 10))
	{
		cout << ex.min() << endl;
		cout << ex.max() << endl;
	}

	example<int> ex2(1,2);
	ex2 = ex;
	//example<int> ex2 = ex;				//这个语句是无效的！不能使用
	cout << ex2.min() << endl;
	cout << ex2.max() << endl;
	cout << ex2[5] << endl;
	//cout<<ex2[-1]<<endl;
	ex2.print();
	ex2.min(2);
	ex2.print();
	ex2.max(12);
	ex2.print();//问题就在于后者ex2的析构函数上并没有运行成功

	//在VS2019中，能够编译通过但是不能运行，在codeblocks中可以运行
	return 0;
}
