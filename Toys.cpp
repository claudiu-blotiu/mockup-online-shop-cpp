#include "Toys.h"

Toys::Toys(int minimAge, int id, int weight, int price, int stock) :Products(id, "Toys", weight, price, stock)
{
	this->minimAge = minimAge;
}

void Toys::set_minimAge(int minimAge)
{
	this->minimAge = minimAge;
}
int Toys::get_minimAge()
{
	return this->minimAge;
}

string Toys::description()
{
	string text = Products::description();

	text += "Minim Age: " + to_string(this->minimAge) + "\n";

	return text;
}

string Toys::to_save()
{
	string text = "";

	text += to_string(this->minimAge) + " ";
	text += to_string(this->getId()) + " ";
	text += this->getName() + " ";
	text += to_string(this->getWeight()) + " ";
	text += to_string(this->getPrice()) + " ";
	text += to_string(this->getStock());

	return text;
}






