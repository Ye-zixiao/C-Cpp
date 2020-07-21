#pragma once

#include<iostream>

struct FlyBehavior {
	virtual void fly(void) const= 0;
};

struct FlyWithWings :FlyBehavior {
	void fly(void) const override {
		std::cout << "I'm flying" << std::endl;
	}
};

struct FlyNoWay :FlyBehavior {
	void fly(void) const override {
		std::cout << "I can't fly!" << std::endl;
	}
};

struct FlyRocketPowered :FlyBehavior {
	void fly(void) const override {
		std::cout << "I'm flying with a rocket!" << std::endl;
	}
};