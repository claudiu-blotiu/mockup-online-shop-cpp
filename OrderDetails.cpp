#include "OrderDetails.h"

OrderDetails::OrderDetails(int id, int orderId, int productId, int price, int quantity)
{
	this->id = id;
	this->orderId = orderId;
	this->productId = productId;
	this->price = price;
	this->quantity = quantity;
}

void OrderDetails::setId(int id)
{
	this->id = id;
}
int OrderDetails::getId()
{
	return this->id;
}

void OrderDetails::setorderId(int orderId)
{
	this->orderId = orderId;
}
int OrderDetails::getorderId()
{
	return this->orderId;
}

void OrderDetails::setproductId(int productId)
{
	this->productId = productId;
}
int OrderDetails::getproductId()
{
	return this->productId;
}

void OrderDetails::setPrice(int price)
{
	this->price = price;
}
int OrderDetails::getPrice()
{
	return this->price;
}

void OrderDetails::setQuantity(int quantity)
{
	this->quantity = quantity;
}
int OrderDetails::getQuantity()
{
	return this->quantity;
}

string OrderDetails::description()
{
	string text = "";

	text += "Id: " + to_string(this->id) + "\n";
	text += "OrderId: " + to_string(this->orderId) + "\n";
	text += "ProductId: " + to_string(this->productId) + "\n";
	text += "Price: " + to_string(this->price) + "\n";
	text += "Quantity: " + to_string(this->quantity)+"\n";

	return text;
}

string OrderDetails::toSave()
{
	string text = "";

	text += to_string(this->id) + " ";
	text += to_string(this->orderId) + " ";
	text += to_string(this->productId) + " ";
	text += to_string(this->price) + " ";
	text += to_string(this->quantity);

	return text;
}