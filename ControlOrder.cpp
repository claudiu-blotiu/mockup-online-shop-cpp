#include "ControlOrder.h"

ControlOrder::ControlOrder()
{
	list = new Order*[100];

	load();
}

void ControlOrder::add(Order* a)
{
	list[size] = a;
	size++;
}

void ControlOrder::show()
{
	for (int i = 0; i < size; i++)
	{
		cout << list[i]->description();
		cout << endl;
	}
}

int ControlOrder::poz(int customerId)
{
	for (int i = 0; i < size; i++)
	{
		if (list[i]->getcustomerId() == customerId)
		{
			return i;
		}
	}

	return -1;
}

void ControlOrder::Delete(int customerId)
{
	int p = poz(customerId);
	for (int i = p; i < size - 1; i++)
	{
		list[i] = list[i + 1];
	}
	size--;
}

int ControlOrder::nextId()
{
	if (size == 0) {
		return 1;
	}

	return list[size - 1]->getId() + 1;
}

void ControlOrder::updatecustomerId(int customerId, int newCustomerId)
{
	int p = poz(customerId);
	if(p != -1)
	{
		list[p]->setcumstomerID(newCustomerId);
	}
	else
	{
		cout << "Customer Id does not match."<<endl;
	}
}

void ControlOrder::updateAmmount(int customerId, int newAmmount)
{
	int p = poz(customerId);
	if (p != -1)
	{
		list[p]->setammount(newAmmount);
	}
	else {
		cout << "Ammount not found"<<endl;
	}
}

void ControlOrder::updateShippingAdress(int customerId, string newShippingAdress)
{
	int p = poz(customerId);
	if (p != -1)
	{
		list[p]->setshippingAdress(newShippingAdress);
	}
	else {
		cout << "Shipping adress not found"<<endl;
	}
}

void ControlOrder::updateOrderAdress(int customerId, string newOrderAdress)
{
	int p = poz(customerId);
	if (p != -1)
	{
		list[p]->setorderAdress(newOrderAdress);
	}
	else {
		cout << "Wrong Order adress."<<endl;
	}
}

void ControlOrder::updateOrderEmail(int customerId, string newOrderEmail)
{
	int p = poz(customerId);
	if (p != -1)
	{
		list[p]->setorderEmail(newOrderEmail);
	}
	else {
		cout << "Wrong Order Email" << endl;
	}
}

void ControlOrder::updateOrderDate(int customerId, int newOrderDate)
{
	int p = poz(customerId);
	if (p != -1)
	{
		list[p]->setorderDate(newOrderDate);
	}
	else
	{
		cout << "Wrong Order date" << endl;
	}
}

void ControlOrder::updateOrderStatus(int customerId, bool newOrderStatus)
{
	int p = poz(customerId);
	if (p != -1)
	{
		list[p]->setorderStatus(newOrderStatus);
	}
	else
	{
		cout << "Wrong Order status"<<endl;
	}
}

Order* ControlOrder::getHistory(int customerId, int& nr)
{
	nr = 0;

	Order* orders = new Order[100];

	for (int i = 0; i < size; i++) {

		if (list[i]->getcustomerId() == customerId) {

			orders[nr] = *list[i];

			nr++;
		}
	}

	return orders;
}

void ControlOrder::load()
{
	ifstream read("Order.txt");

	while(!read.eof())
	{
		int id;
		read >> id;
		int customerId;
		read >> customerId;
		int ammount;
		read >> ammount;
		string shippingAdress;
		read >> shippingAdress;
		string orderAdress;
		read >> orderAdress;
		string orderEmail;
		read >> orderEmail;
		int orderDate;
		read >> orderDate;
		bool orderStatus;
		read >> orderStatus;

		if (id > 0)
		{
			Order* g=new Order(id, customerId, ammount, shippingAdress, orderAdress, orderEmail, orderDate, orderStatus);

			this->add(g);
		}
	}
}

string ControlOrder::toSave()
{
	string text = "";
	int i = 0;
	for ( i = 0; i < size-1; i++)
	{
		text += list[i]->toSave() + "\n";
	}

	text += list[i]->toSave();
	return text;
}

void ControlOrder::save()
{
	ofstream f("Order.txt");

	f << this->toSave();

	f.close();
}
