#include<iostream>
using namespace::std;

class Base {
public:
	void func(Base& item) {
		item = *this;
	}
	int pub_value = 1;
protected:
	int pro_value = 2;
private:
	int pri_value = 3;
};

class Derived_pub :public Base {
public:
	void func(Base& item) {
		item = *this;
	}
};

class Derived_pro :protected Base {
public:
	void func(Base& item) {
		item = *this;
	}
};

class Derived_pri :private Base {
public:
	void func(Base& item) {
		item = *this;
	}
};

class Derived_from_pub :public Derived_pub {
public:
	void func(Base& item) {
		item = *this;
	}
};

class Derived_from_pro :public Derived_pro {
public:
	void func(Base& item) {
		item = *this;
	}
};

class Derived_from_pri :public Derived_pri {
public:
	void func(Base& item) {
		item = *this;
	}
};
