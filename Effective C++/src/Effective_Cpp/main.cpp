#include<iostream>
#include<memory>
#include"FlyBehavior.h"
#include"QuackBehavior.h"
#include"Duck.h"
using namespace std;

class MallardDuck :public Duck {
public:
	MallardDuck():
		Duck(new FlyWithWings(),new Quack()){}
	void display(void) const override {
		cout << "I'm a real MallardDuck!" << std::endl;
	}
};

class ModelDuck :public Duck {
public:
	ModelDuck():
		Duck(new FlyNoWay(),new Quack()){}
	void display(void) const override {
		cout << "I'm a model duck!" << endl;
	}
};

int main(void) {
	shared_ptr<Duck> spduck(new MallardDuck());
	spduck->performFly();
	spduck->performQuack();

	shared_ptr<Duck> spdduck(new ModelDuck());
	spdduck->performFly();
	spdduck->setFlyBehavior(new FlyRocketPowered());
	spdduck->performFly();

	return 0;
}