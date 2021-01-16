#include<memory>
#include<iostream>
using namespace std;

template<typename elemType>				//最简单的智能指针
class my_auto_ptr
{
public:
	my_auto_ptr(elemType* ptr)
		:_ptr(ptr){}
	~my_auto_ptr()
	{
		delete _ptr;
		cout << "free!" << endl;
	}

	elemType& operator*() { return *_ptr; }
	elemType* operator->() { return _ptr; }
	bool empty() const
	{
		if (!_ptr)
			return true;
		else
			return false;
	}

private:
	elemType* _ptr;
};

int main(void)
{
	my_auto_ptr<int> ptemp(new int(123));
	if (!ptemp.empty())
		cout << *ptemp << endl;
	else
		cout << "no?" << endl;

	return 0;
}
