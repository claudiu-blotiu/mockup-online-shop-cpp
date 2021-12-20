#include "Electronics.h"

Electronics::Electronics(string marca, int id, int weight, int price, int stock) :Products(id, "Electronics", weight, price, stock)
{
	this->marca = marca;
}

void Electronics::set_marca(string marca)
{
	this->marca = marca;
}
string Electronics::get_marca()
{
	return this->marca;
}

string Electronics::description()
{
	string text = Products::description();

	text += "Marca: " + this->marca + "\n";

	return text;
}

string Electronics::to_save()
{
	string text = "";

	text += this->marca + " ";
	text += to_string(this->getId()) + " ";
	text += this->getName() + " ";
	text += to_string(this->getWeight()) + " ";
	text += to_string(this->getPrice()) + " ";
	text += to_string(this->getStock());

	return text;
}

