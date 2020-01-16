//main.cpp

#include "triangular.h"

int main()
{
	Triangular tri(20, 1);
	Triangular::iterator it = tri.begin();
	Triangular::iterator end_it = tri.end();

	cout << "Triangular Series of " << tri.length() << " elements\n";

	while (it != end_it)
	{
		cout << *it << ' ';
		++it;
	}
	cout << endl;

	////Triangular::display(5, 1);

	//Triangular tri3;
	//cin >> tri3;
	//cout << tri3;

	return 0;
}