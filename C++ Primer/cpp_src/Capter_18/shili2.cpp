#include<iostream>
using namespace::std;

/*
 * �������������ӵ��������ж�function try block����try��������
 * https://www.it1352.com/467767.html
 * https://blog.csdn.net/tutuxs/article/details/76034666
 *
*/

class ErrMaybe {
	int value;
public:
	ErrMaybe(int val) :value(0) {
		if (val > 100)throw runtime_error("Error");
		else value = val;
	}

	int get(void) const {
		return value;
	}
};

class withErrMaybe {
	ErrMaybe item;
public:
	withErrMaybe(int val)try:
		item(val) {}
	catch (runtime_error& err) {
		cerr << err.what() << endl;//�������û�д���ɾ��������ֽ����err���׳��ˣ�����
	}d

	int get(void) const {
		return item.get();
	}
};

class withErrMaybe_notry {
	ErrMaybe item;
public:
	withErrMaybe_notry(int val):
		item(val){}

	int get(void) const {
		return item.get();
	}
};

int main(void)
{
	try {
		withErrMaybe item(1000);
		cout << item.get() << endl;
	}
	catch (runtime_error& err) {
		cerr << err.what() << endl;
	}

	try {
		withErrMaybe_notry item(1000);
		cout << item.get() << endl;
	}
	catch (runtime_error& err) {
		cerr << err.what() << endl;
	}

	return 0;
}
