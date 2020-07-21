#pragma once

#include<iostream>

struct QuackBehavior {
	virtual void quack(void) const= 0;
};

struct Quack : QuackBehavior {
	void quack(void) const override {
		std::cout << "Quack" << std::endl;
	}
};

struct Squeak :QuackBehavior {
	void quack(void) const override {
		std::cout << "Squeak" << std::endl;
	}
};

struct MuteQuack :QuackBehavior {
	void quack(void) const override {
		std::cout << "<<Silence>>" << std::endl;
	}
};