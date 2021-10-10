#include "order.h"

Order::Order(int id, int customerId, int ammount, string shippingAdress, string orderAdress, string orderEmail, int orderDate, bool orderStatus)
{
	this->id = id;
	this->customerId = customerId;
	this->ammount = ammount;
	this->shippingAdress = shippingAdress;
	this->orderAdress = orderAdress;
	this->orderEmail = orderEmail;
	this->orderDate = orderDate;
	this->orderStatus = orderStatus;

}

void Order::setId(int id)
{
	this->id = id;
}
int Order::getId()
{
	return this->id;
}

void Order::setcumstomerID(int customerId)
{
	this->customerId = customerId;
}
int Order::getcustomerId()
{
	return this->customerId;
}

void Order::setammount(int ammount)
{
	this->ammount = ammount;
}
int Order::getammount()
{
	return this->ammount;
}

void Order::setshippingAdress(string shippingAdress)
{
	this->shippingAdress = shippingAdress;
}
string Order::getshippingAdress()
{
	return this->shippingAdress;
}

void Order::setorderAdress(string orderAdress)
{
	this->orderAdress = orderAdress;
}
string Order::getorderAdress()
{
	return this->orderAdress;
}

void Order::setorderEmail(string orderEmail)
{
	this->orderEmail = orderEmail;
}
string Order::getorderEmail()
{
	return this->orderEmail;
}

void Order::setorderDate(int orderDate)
{
	this->orderDate = orderDate;
}
int Order::getorderDate()
{
	return this->orderDate;
}

void Order::setorderStatus(bool orderStatus)
{
	this->orderStatus = orderStatus;
}
bool Order::getorderStatus()
{
	return this->orderStatus;
}

string Order::description()
{
	string text = "";

	text += "Id: " + to_string(this->id) + "\n";
	text += "Customer Id: " + to_string(this->customerId) + "\n";
	text += "Ammount:" + to_string(this->ammount) + "\n";
	text += "Shipping Adress: " + this->shippingAdress + "\n";
	text += "Order Adress: " + this->orderAdress + "\n";
	text += "Order Email: " + this->orderEmail + "\n";
	text += "Order Date: " + to_string(this->orderDate) + "\n";
	if (orderStatus != 0)
	{
		text += "Avalible.\n";
	}
	else
	{
		text += "Processing.\n";
	}
	
	return text;
}

string Order::toSave()
{
	string text = "";
	text += to_string(this->id) + " ";
	text += to_string(this->customerId) + " ";
	text += to_string(this->ammount) + " ";
	text += this->shippingAdress + " ";
	text += this->orderAdress + " ";
	text += this->orderEmail + " ";
	text += to_string(this->orderDate) + " ";
	text += to_string(this->orderStatus);
	return text;
}
