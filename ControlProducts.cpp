#include "ControlProducts.h"

ControlProducts::ControlProducts()
{
	load();
}

void ControlProducts::add(Products a)
{
	product[size] = a;
	size++;
}

void ControlProducts::show()
{
	for (int i = 0; i < size; i++)
	{
		cout << product[i].description();
		cout << endl;
	}
}

int ControlProducts::poz(string name)
{
	for (int i = 0; i < size; i++)
	{
		if (product[i].getName() == name)
		{
			return i;
		}
	}
	return -1;
}

void ControlProducts::Delete(string name)
{
	int p = poz(name);
	for (int i = p; i < size-1; i++)
	{
		product[i] = product[i + 1];
	}
	size--;
}

int ControlProducts::nextId() {

	if (size == 0) {
		return 1;
	}

	return product[size - 1].getId() + 1;
}

void ControlProducts::updateName(string name, string newName)
{
	int p = poz(name);
	if (p != -1)
	{
		product[p].setName(newName);
	}
	else {
		cout << "Name not found" << endl;
	}
}

void ControlProducts::updateWeight(string name, int newWeight)
{
	int p = poz(name);
	if (p != -1)
	{
		product[p].setWeight(newWeight);
	}
	else
	{
		cout << "Wrong weight." << endl;
	}
}

void ControlProducts::updatePrice(string name, int newPrice)
{
	int p = poz(name);
	if (p != -1)
	{
		product[p].setPrice(newPrice);
	}
	else
	{
		cout << "The Price is wrong"<<endl;
	}
}

void ControlProducts::updateStock(string name, int newStock)
{
	int p = poz(name);
	if (p != -1)
	{
		product[p].setStock(newStock);
	}
	else
	{
		cout << "The Product dosent exist"<<endl;
	}
}

Products ControlProducts::getProduct(string name)
{
	
	int pozitie = poz(name);

	return  product[pozitie];

}

Products ControlProducts::getProduct1(int productID)
{
	for (int i = 0; i < size; i++)
	{
		if (product[i].getId() == productID)
		{
			return product[i];
		}
	}
}

void ControlProducts::load()
{
	ifstream read("products.txt");

	while (!read.eof())
	{
		int id;
		read >> id;
		string name;
		read >> name;
		int weight;
		read >> weight;
		int price;
		read >> price;
		int stock;
		read >> stock;

		if (name != "")
		{
			Products p(id,name, weight, price, stock);
			this->add(p);
		}
	}
}

string ControlProducts::toSave()
{
	string text = "";
	int i = 0;
	for (i = 0; i < size-1; i++)
	{
		text += product[i].toSave() + "\n";
	}
	text += product[i].toSave();
	return text;
}

void ControlProducts::save()
{
	ofstream f("products.txt");

	f << this->toSave();

	f.close();
}
