#include<iostream>
#include<cmath>
#include<iomanip>
using namespace::std;

int main(void)
{
	cout << showbase << uppercase << hexfloat << nouppercase;
	cout << "Float1:" << setw(20) << sqrt(2.0) << "end here" << endl;
	cout << "Float2:" << setw(20) << 1.23 << "end here" << endl;
	for (double d = 0.2; d != 10.2; d += 1)
		cout << "Float3:" << setw(20) << d << "end here" << endl;
}
