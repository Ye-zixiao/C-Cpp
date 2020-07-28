#pragma once

#include<memory>
#include<string>
#include<iostream>
#include"Pizza.h"


class PizzaStore {
public:
	PizzaStore() = default;
	virtual ~PizzaStore() = default;

	std::shared_ptr<Pizza>
		orderPizza(const std::string& type) {
		std::shared_ptr<Pizza> p = nullptr;
		p = createPizza(type);
		p->prepare();
		p->bake();
		p->cut();
		p->box();
		return p;
	}

protected:
	virtual std::shared_ptr<Pizza> createPizza(const std::string& type) = 0;
};

class NYStylePizzaStore :public PizzaStore {
protected:
	std::shared_ptr<Pizza>
		createPizza(const std::string& type) {
		Pizza* p;
		if (type == "cheese")
			p = new NYStyleCheesePizza();
		else
			p = nullptr;
		return std::shared_ptr<Pizza>(p);
	}
};

class ChicagoStylePizzaStore :public PizzaStore {
protected:
	std::shared_ptr<Pizza>
		createPizza(const std::string& type) {
		Pizza* p;
		if (type == "cheese")
			p = new ChicagoStyleCheesePizza();
		else
			p = nullptr;
		return std::shared_ptr<Pizza>(p);
	}
};