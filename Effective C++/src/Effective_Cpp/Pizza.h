#pragma once

#include<string>
#include<iostream>

class Pizza {
	std::string name;
public:
	Pizza(const std::string n):
		name(n){}
	virtual ~Pizza() = default;

	std::string getName(void) const {
		return name;
	}

	virtual void prepare(void) {
		std::cout << "Preparing " << name << std::endl;
		std::cout << "Tossing dough..." << std::endl;
		std::cout << "Adding sauce..." << std::endl;
		std::cout << "Adding toppings..." << std::endl;
	}

	virtual void bake(void) {
		std::cout << "Bake for 25 minutes at 350" << std::endl;
	}

	virtual void cut(void) {
		std::cout << "Cutting the pizza into diagonal slices" << std::endl;
	}

	virtual void box(void) {
		std::cout << "Place pizza in official PizzaStore box" << std::endl;
	}

};

class NYStyleCheesePizza :public Pizza {
public:
	NYStyleCheesePizza() :
		Pizza("NY Style Sauce and Cheese Pizza") {}
};

class ChicagoStyleCheesePizza :public Pizza {
public:
	ChicagoStyleCheesePizza():
		Pizza("Chicago Style Deep Dish Cheese Pizza"){}

	void cut(void) override {
		std::cout << "Cutting the pizza into square slices" << std::endl;
	}
};
