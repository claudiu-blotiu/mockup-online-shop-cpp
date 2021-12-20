#include "Food.h"

Food::Food(string type, int id, int weight, int price, int stock) :Products(id, "Food", weight, price, stock)
{
	this->type = type;
}

void Food::set_type(string type)
{
	this->type = type;
}
string Food::get_type()
{
	return this->type;
}

string Food::description()
{
	string text = Products::description();

	text += "Type: " + this->type + "\n";

	return text;
}

string Food::to_save()
{
	string text = "";

	text += this->type + " ";
	text += to_string(this->getId()) + " ";
	text += this->getName() + " ";
	text += to_string(this->getWeight()) + " ";
	text += to_string(this->getPrice()) + " ";
	text += to_string(this->getStock());

	return text;
}
