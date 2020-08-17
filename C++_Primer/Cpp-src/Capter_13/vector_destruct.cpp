#include<iostream>
#include<vector>
#include<memory>
#include<string>
using namespace::std;

class Test {
public:
	Test(int val) :value(val) {
		cout << "1——Test(int val)" << endl;
	}
	Test() :value(0) {
		cout << "2——Test()" << endl;
	}
	Test(const Test& item) :value(item.value) {
		cout << "3——Test(const Test&item)" << item.value << endl;
	}
	Test& operator=(const Test& item) {
		value = item.value;
		cout << "4——Test& operator=(const Test&item)" << endl;
		return *this;
	}
	~Test() {
		cout << "5——~Test()" << value << endl;
	}


private:
	int value;
};

int main(void)
{
	Test v1(10);//1
	Test v2;//2
	cout << endl;

	vector<Test> tvec;
	cout << tvec.capacity() << endl;
	tvec.push_back(v1);
	cout << tvec.capacity() << endl;
	tvec.push_back(v2);
	cout << tvec.capacity() << endl;
	tvec.push_back(32);
	cout << tvec.capacity() << endl;
	//vector<Test> tvec{ v1,v2,32 };//33 1333555
	/*使用列表初始化，根据上面的打印结果33 1333555可以知道执行该语句时vector先在内存中分配了两个Test大小的
	内存单元，然后使用拷贝初始化初始之，但是之后由于添加了一个32，使用转换构造之后准备拷贝初始化vector中的
	元素，但是由于内存中只分配了两个内存单元，最后不得不重新分配动态内存，在这个过程中由于经历了拷贝初始化+
	析构的过程
	*/

	cout << endl;
	return 0;//5*5
}

/*
输出结果：
1——Test(int val)
2——Test()

//1、在一个开始tvec中没有元素，push_back相同通过在内存中分配出一块动态内存大小为1个Test，使用拷贝初始化这个对象
0
3——Test(const Test & item)10
1

//2、由于此时又要添加元素，而容器中的capacity为1，且vector是连续分布的，所以它tvec会在分配大小为2个Test的容量，
使用先前的元素和新添Test用拷贝初始化的方式初始化2个对象，但最后会将原来的动态内存释放掉所以最后有一个析构函数执行
3——Test(const Test & item)0
3——Test(const Test & item)10
5——~Test()10
2

//3、在第三个push_back中，由于括号中的实参不是Test类型，所以先要通过转换构造创建出一个临时Test类对象。但是又由于
容器中的capacity太小，且vector是连续分布的，所以又需要重新分配动态内存，所以又用到了3次拷贝初始化，不过其中一次是
临时Test类对象拷贝初始化其中一个内存块导致的。等所有的元素都创建转移完毕，vector就会释放之前的2个内存块，所以下面有
2个析构函数执行，另外一个析构函数是针对转换构造时创建的临时对象的！
1——Test(int val)
3——Test(const Test & item)32
3——Test(const Test & item)10
3——Test(const Test & item)0
5——~Test()10
5——~Test()0
5——~Test()32
3

5——~Test()10
5——~Test()0
5——~Test()32
5——~Test()0
5——~Test()10

*/
