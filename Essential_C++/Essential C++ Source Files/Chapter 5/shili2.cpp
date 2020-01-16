#include<iostream>
#include<string>
using namespace std;

class LibMat
{
public:
	LibMat() { cout << "LibMat::LibMat() default constructor!\n"; }

	virtual ~LibMat() { cout << "LibMat::~LibMat() destructor!\n"; }
	virtual void print() const									//�麯��
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

	virtual void print() const									/*�麯����
																	ͬ�������ڳ������ʱ����ʵ���о���Ҫ������һ���������
																���ǻ����ͬ��������ֻ��������ʱ�̲���֪�������У�*/
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

class AudioBook : public Book									//�ؼ���public�����������������ʿ��Ʒ�
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
		/*cout << "Book::private:value=" << value;*/			//�����private��Ա���ܱ�������������
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
	const string& return_title() const { return _title; }//��������������ֱ�ӷ��ʻ����е�����

protected:
	string _narrator;					//��˵Ա,������
};

int main(void)
{
	//����һ��Book��
	//cout << "Creating a Book object to print()\n";
	//cout << endl;
	//Book b("The Castle", "Franz Kafka");
	//cout << endl;
	//print(b);								/*�������е�print���������˻����е�print�����������໹���ֳ��˶�̬��������
	//												������reference/ָ��pointer��ָ��Ķ���ֻ�е�ʵ�����е���һ�̲�ȷ����
	//										����������ָ����Book�࣬�������õ�Ҳ��Book���е��麯��			*/
	//cout << endl;

	//����һ��AudioBook��
	/*cout << "Creating an AudioBook object to print()\n";
	cout << endl;
	AudioBook ab("Man Without Qualities",
		"Robert Musil", "Kenneth Meyer");
	cout << endl;
	print(ab);
	cout << endl;*/

	AudioBook ab("Mason and Dixon", "Thomas Pynchon", "Edwin Leonard");
	cout<<endl;

	cout << "The title is " << ab.return_title() << '\n'				/*ʹ��������ʱ�������֡��̳ж����ĳ�Ա����������ĳ�Ա
																�����ߵ�ʹ����ȫ͸�����ͷ·��ǻ���Ķ�����ȫ���������Լ���һ����*/
		<< "The author is " << ab.author() << '\n'
		<< "The narrator is " << ab.narrator() << '\n';
    cout<<endl;

	return 0;
}

/*
-- �̳е��ص㣺
		1.���һ���������Ƿ�װ��public��private���þ���ʵ����һĿ�ġ����ԣ�
		�û����루���⣩���Է���public��Ա�����ܷ���private��Ա��private��Աֻ�������Ա�����ڣ�����Ԫ���ʡ�
		2.�����һ���������Ǽ̳У�protected�����þ���ʵ����һĿ�ġ����ԣ�
		protected��Ա���Ա������������ʣ����ܱ��û����루���⣩����

��������˵��������������ĳ�Ա������Ԫ���ܷ�ֱ�ӷ���ֱ�ӻ���ĳ�ԱûʲôӰ�죬�Ի����Ա�ķ���Ȩ��ֻ������еķ���˵�����йء�

-- ��������˵�����������ǿ����������û�����������������������ڣ����ڻ����Ա�ķ���Ȩ�ޡ�
		�������private˵����˵���������಻�ܷ��ʣ���private�̳з�ʽֻ�ǽ�����public��Ա��protected��Ա��
		private��Ա�ķ����������������зֱ��ɣ�private, private, private,��Ӱ���ֻ������������ķ���Ȩ�ޣ�
		�����������ڻ��ǿ��Է�����Щ�����е�public��protected��Ա����Ȼ�������ڱ����private����

-- C++����public, protected, private���ּ̳з�ʽ��������Ӧ�ظı�����������û��Լ��������������ķ���Ȩ�ޡ�
		1.public�̳У�����public��Ա��protected��Ա��private��Ա�ķ����������������зֱ��ɣ�public, protected, private
		2.protected�̳У�����public��Ա��protected��Ա��private��Ա�ķ����������������зֱ��ɣ�protected, protected, private
		3.private�̳У�����public��Ա��protected��Ա��private��Ա�ķ����������������зֱ��ɣ�private, private, private

-- ���������ּ̳з�ʽ���������㶼û�иı䣺
		1.private��Աֻ�ܱ������Ա�����ڣ�����Ԫ���ʣ����ܱ���������ʣ�
		2.protected��Ա���Ա���������ʡ�

*/
