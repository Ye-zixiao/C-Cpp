#include<iostream>
#include<fstream>
#include"TextQuery.h"
#include"Query.h"
using namespace::std;

int main(void)
{
	ifstream infile("infile.txt", ifstream::in);
	if (!infile) {
		cerr << "Fuck" << endl;
		return -1;
	}
	TextQuery text(infile);

	Query q = Query("mother") & Query("should") | Query("will");
	cout << q.eval(text);
	cout << endl;
	cout << q.eval(text, 3, 11);//[lower,upper]

	return 0;
}