#pragma once

#include"Test.h"

class ConcreteTest1:public Test {
public:
	ConcreteTest1(int v);

	int get(void) const override;
	ConcreteTest1& modify(int value) override;

private:
	int value;
};

class ConcreteTest2 :public Test {
public:
	ConcreteTest2(int v);

	int get(void) const override;
	ConcreteTest2& modify(int value) override;

private:
	int value;
};