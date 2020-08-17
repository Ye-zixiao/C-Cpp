#include<iostream>
#include<cstdio>
using namespace::std;

int main(void)
{
	char charr[11];
	//cin.get(charr, 10, ';');//还会读取一个换行符'\n'
	cin.getline(charr, 10, ';');
	cout << charr;
	//cin.unget();
	cout << cin.gcount() << endl;

	//char charArr[11];
	//cin.read(charArr, 10);
	//cout << charArr << endl;

	char charARR[11] = "helloworld";
	cout.write(charARR, 10);

	return 0;
}
