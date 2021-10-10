#include "Products.h"

Products::Products(int id, string name, int weight, int price, int stock)
{
	this->id = id;
	this->name = name;
	this->weight = weight;
	this->price = price;
	this->stock = stock;
}

void Products::setId(int id)
{
	this->id = id;
}
int Products::getId()
{
	return this->id;
}

void Products::setName(string name)
{
	this->name = name;
}
string Products::getName()
{
	return this->name;
}

void Products::setWeight(int weight)
{
	this->weight = weight;
}
int Products::getWeight()
{
	return this->weight;
}

void Products::setPrice(int price)
{
	this->price = price;
}
int Products::getPrice()
{
	return this->price;
}

void Products::setStock(int stock)
{
	this->stock = stock;
}
int Products::getStock()
{
	return this->stock;
}

string Products::description()
{
	string text = "";

	text += "Id: " + to_string(this->id) + "\n";
	text += "Name: " + this->name + "\n";
	text += "Weight: " + to_string(this->weight) + "\n";
	text += "Price: " + to_string(this->price) + "\n";
	text += "Stock: " + to_string(this->stock) + "\n";
	
	return text;
}

string Products::toSave()
{
	string text = "";

	text += to_string(this->id) + " ";
	text += this->name + " ";
	text += to_string(this->weight) + " ";
	text += to_string(this->price) + " ";
	text += to_string(this->stock);

	return text;
}


