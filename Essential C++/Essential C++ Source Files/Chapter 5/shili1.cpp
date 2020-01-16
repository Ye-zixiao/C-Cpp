#include<iostream>
using namespace std;

class LibMat
{
public:
	LibMat() { cout << "LibMat::LibMat() default constructor!\n"; }

	virtual ~LibMat() { cout << "LibMat::~LibMat() destructor!\n"; }
	virtual void print() const
	{
		cout << "LibMat::print() -- I am a LibMat object!\n";
	}

};

void print(const LibMat& mat)
{
	cout << "in global print():about to print mat.print()\n";
	mat.print();
}

int main(void)
{
	cout << "Creating a LibMat object to print()\n";
	LibMat libmat;
	print(libmat);

	return 0;
}
