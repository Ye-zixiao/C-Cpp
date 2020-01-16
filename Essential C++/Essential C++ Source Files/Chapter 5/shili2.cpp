#include<iostream>
#include<string>
using namespace std;

class LibMat
{
public:
	LibMat() { cout << "LibMat::LibMat() default constructor!\n"; }

	virtual ~LibMat() { cout << "LibMat::~LibMat() destructor!\n"; }
	virtual void print() const									//虚函数
	{
		cout << "LibMat::print() -- I am a LibMat object!\n";
	}

};

void print(const LibMat& mat)
{
	cout << "in global print():about to print mat.print()\n";
	mat.print();
}

class Book : public LibMat
{
public:
	Book(const string& title, const string& author)
		:_title(title), _author(author)
	{
		cout << "Book::Book(" << _title << ", "
			<< _author << ") constructor\n";
	}

	virtual ~Book() { cout << "Book::~Book() destructor~\n"; }

	virtual void print() const									/*虚函数：
																	同名函数在程序调用时，在实际中究竟要调用哪一个派生类或
																者是基类的同名函数，只有在运行时刻才能知晓并进行！*/
	{
		cout << "Book::print() -- I am a Book object!\n"
			<< "My title is: " << _title << '\n'
			<< "My author is:" << _author << endl;
	}

	const string& title() const { return _title; }
	const string& author() const { return _author; }

protected:
	string _title;
	string _author;

//private:
//	int value = 0;
};

class AudioBook : public Book									//关键字public在这里叫做派生类访问控制符
{
public:
	AudioBook(const string& title, const string& author, const string& narrator)
		:Book(title, author),
		_narrator(narrator)
	{
		cout << "AudioBook::AudioBook(" << _title
			<< ", " << _author
			<< ", " << _narrator
			<< ") constructor\n";
		/*cout << "Book::private:value=" << value;*/			//基类的private成员不能被派生类所访问
	}

	~AudioBook(){ cout << "AudioBook::~AudioBook() destructor~\n"; }

	virtual void print() const
	{
		cout << "AudioBook::print() -- I am a AudioBook object!\n"
			<< "My title is: " << _title << '\n'
			<< "My author is: " << _author << '\n'
			<< "My narrator is: " << _narrator << endl;
	}
	const string& narrator() const { return _narrator; }
	const string& return_title() const { return _title; }//这表明派生类可以直接访问基类中的数据

protected:
	string _narrator;					//解说员,叙述者
};

int main(void)
{
	//构造一个Book类
	//cout << "Creating a Book object to print()\n";
	//cout << endl;
	//Book b("The Castle", "Franz Kafka");
	//cout << endl;
	//print(b);								/*派生类中的print函数覆盖了基类中的print函数，而且类还表现出了多态的特征：
	//												即引用reference/指针pointer所指向的对象只有到实际运行的那一刻才确定。
	//										在这里引用指向了Book类，而所调用的也是Book类中的虚函数			*/
	//cout << endl;

	//构造一个AudioBook类
	/*cout << "Creating an AudioBook object to print()\n";
	cout << endl;
	AudioBook ab("Man Without Qualities",
		"Robert Musil", "Kenneth Meyer");
	cout << endl;
	print(ab);
	cout << endl;*/

	AudioBook ab("Mason and Dixon", "Thomas Pynchon", "Edwin Leonard");
	cout<<endl;

	cout << "The title is " << ab.return_title() << '\n'				/*使用派生类时不必区分“继承而来的成员”和自身定义的成员
																。两者的使用完全透明！就仿佛是基类的东西完全是派生类自己的一样的*/
		<< "The author is " << ab.author() << '\n'
		<< "The narrator is " << ab.narrator() << '\n';
    cout<<endl;

	return 0;
}

/*
-- 继承的特点：
		1.类的一个特征就是封装，public和private作用就是实现这一目的。所以：
		用户代码（类外）可以访问public成员而不能访问private成员；private成员只能由类成员（类内）和友元访问。
		2.类的另一个特征就是继承，protected的作用就是实现这一目的。所以：
		protected成员可以被派生类对象访问，不能被用户代码（类外）访问

派生访问说明符对于派生类的成员（及友元）能否直接访问直接基类的成员没什么影响，对基类成员的访问权限只与基类中的访问说明符有关。

-- 派生访问说明符的作用是控制派生类用户（包括派生类的派生类在内）对于基类成员的访问权限。
		即父类的private说明符说明了派生类不能访问，而private继承方式只是将基类public成员，protected成员，
		private成员的访问属性在派生类中分别变成：private, private, private,这影响的只是派生类类外的访问权限，
		派生类在类内还是可以访问那些基类中的public和protected成员（虽然它们现在变成了private）。

-- C++中有public, protected, private三种继承方式，它们相应地改变了派生类的用户以及派生类的派生类的访问权限。
		1.public继承：基类public成员，protected成员，private成员的访问属性在派生类中分别变成：public, protected, private
		2.protected继承：基类public成员，protected成员，private成员的访问属性在派生类中分别变成：protected, protected, private
		3.private继承：基类public成员，protected成员，private成员的访问属性在派生类中分别变成：private, private, private

-- 但无论哪种继承方式，上面两点都没有改变：
		1.private成员只能被本类成员（类内）和友元访问，不能被派生类访问；
		2.protected成员可以被派生类访问。

*/
