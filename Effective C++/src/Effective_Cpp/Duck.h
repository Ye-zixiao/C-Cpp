#pragma once

#include<iostream>
#include<memory>
#include"FlyBehavior.h"
#include"QuackBehavior.h"

class Duck {
public:
	Duck(FlyBehavior*pfly,QuackBehavior*pquack):
		spfly(pfly),spquack(pquack){}
	virtual ~Duck() = default;

	void swim(void) const {
		std::cout << "All ducks float,even decoys!" << std::endl;
	}
	void performFly(void) const {
		spfly->fly();
	}
	void performQuack(void) const {
		spquack->quack();
	}
	void setFlyBehavior(FlyBehavior* sp) {
		spfly.reset(sp);
	}
	void setQuackBehavior(QuackBehavior* sp) {
		spquack.reset(sp);
	}
	virtual void display(void) const = 0;


private:
	std::shared_ptr<FlyBehavior> spfly;
	std::shared_ptr<QuackBehavior> spquack;
};