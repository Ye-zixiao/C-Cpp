#include"Test.h"
#include"concreteTest.h"

ConcreteTest1::ConcreteTest1(int v):value(v){}

int ConcreteTest1::get(void) const {
	return value + 100;
}

ConcreteTest1& ConcreteTest1::modify(int v) {
	value = v;
	return *this;
}

ConcreteTest2::ConcreteTest2(int v):value(v){}

int ConcreteTest2::get(void) const {
	return value;
}

ConcreteTest2& ConcreteTest2::modify(int v) {
	value = v;
	return *this;
}

Test* Test::creator(int value, mem m) {
	switch (m) {
	case C1:
		return new ConcreteTest1(value);
	case C2:
		return new ConcreteTest2(value);
	default:
		return nullptr;
	}
}