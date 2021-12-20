#include "Customer.h"

Customer::Customer(int id, string email, string password, string fullName, string billingAdress, string shippingAdress, string country, int phone)
{
	this->id = id;
	this->email = email;
	this->password = password;
	this->fullName = fullName;
	this->billingAdress = billingAdress;
	this->shippingAdress = shippingAdress;
	this->country = country;
	this->phone = phone;
}

void Customer::setId(int id)
{
	this->id = id;
}
int Customer::getId()
{
	return this->id;
}

void Customer::setEmail(string email)
{
	this->email = email;
}
string Customer::getEmail()
{
	return this->email;
}

void Customer::setPassword(string password)
{
	this->password = password;
}
string Customer::getPassword()
{
	return this->password;
}

void Customer::setFullname(string fullName)
{
	this->fullName = fullName;
}
string Customer::getFullname()
{
	return this->fullName;
}

void Customer::setBillingadress(string billingAdress)
{
	this->billingAdress = billingAdress;
}
string Customer::getBillingadress()
{
	return this->billingAdress;
}

void Customer::setShippingAdress(string shippingAdress)
{
	this->shippingAdress = shippingAdress;
}
string Customer::getShippingAdress()
{
	return this->shippingAdress;
}

void Customer::setCountry(string country)
{
	this->country = country;
}
string Customer::getCountry()
{
	return this->country;
}

void Customer::setPhone(int phone)
{
	this->phone = phone;
}
int Customer::getPhone()
{
	return this->phone;
}

string Customer::description()
{
	string text = "";

	text += "Id: " + to_string(this->id) + "\n";
	text += "Email: " + this->email + "\n";
	text += "Password: " + this->password + "\n";
	text += "Full Name: " + this->fullName + "\n";
	text += "Billing Adress: " + this->billingAdress + "\n";
	text += "Shipping Adress: " + this->shippingAdress + "\n";
	text += "Country: " + this->country + "\n";
	text += "Phone: " + to_string(this->phone) + "\n";

	return text;
}

string Customer::toSave()
{
	string text = "";
	text += to_string(this->id) + " ";
	text += this->email + " ";
	text += this->password + " ";
	text += this->fullName + " ";
	text += this->billingAdress + " ";
	text += this->shippingAdress + " ";
	text += this->country + " ";
	text += to_string(this->phone);
	return text;
}






