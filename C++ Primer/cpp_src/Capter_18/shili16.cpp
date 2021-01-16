#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace::std;

struct Base1 {
	void print(int) const;
protected:
	int ival;
	double dval;
	char cval;
private:
	int* id;
};

struct Base2 {
	void print(double) const;
protected:
	double fval;
private:
	double dval;
};

struct Derived :public Base1 {
	void print(string) const;
protected:
	string sval;
	double dval;
};

struct MI :Derived, Base2 {
	void print(vector<double>);
	void foo(double);
protected:
	int* ival;
	vector<double> dvec;
};


/*

Base1----->Derived------|
						|
						--->MI
		   Base2--------|

*/
int ival;
double dval;
void MI::foo(double cval) {
	int dval;
	dval = Base1::dval + Derived::dval;
	Base2::fval = dvec.back();
	sval[0] = Base1::cval;
}


int main(void)
{
	MI mi;
	//mi.print(21);//下面的print的成员函数在MI多继承派生类中都被print(vector<double>)隐藏
	//mi.print(string());
	//mi.print(2.2);
	mi.print(vector<double>());
	mi.Base1::print(32);

	return 0;
}
