#include<iostream>
#include<string>
using std::cout;
using std::string;
using std::endl;

class Y {
public:
	Y() = default;
	Y(const Y& item):
		value(item.value){
		cout << "Y(const Y&)" << endl;
	}


private:
	int value;
};

struct hasY {
	hasY() = default;
	hasY(hasY&&) = default;
	Y mem;
};

int main(void)
{
	hasY hy, hy2 = std::move(hy);
}
