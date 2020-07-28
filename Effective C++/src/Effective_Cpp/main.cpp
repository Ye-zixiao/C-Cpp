#include<iostream>
#include<string>
#include<memory>
#include"PizzaStore.h"
#include"Pizza.h"
using namespace std;


int main(void)
{
	NYStylePizzaStore nyStore;
	ChicagoStylePizzaStore ccStore;

	shared_ptr<Pizza> pizza = nyStore.orderPizza("cheese");
	cout << "Ethan ordered a " << pizza->getName() << endl;

	cout << endl;
	pizza = ccStore.orderPizza("cheese");
	cout << "Joel ordered a " << pizza->getName() << endl;

	return 0;
}