#include "ControlOrderDetails.h"

ControlOrderDetails::ControlOrderDetails()
{
	load();
}

void ControlOrderDetails::add(OrderDetails a)
{
	detail[size] = a;
	size++;
}

void ControlOrderDetails::show()
{
	for (int i = 0; i < size; i++)
	{
		cout << detail[i].description();
		cout << endl;
	}
}

int ControlOrderDetails::poz(int orderId)
{
	for (int i = 0; i < size; i++)
	{
		if (detail[i].getorderId() == orderId)
		{
			return i;
		}
	}
	return -1;
}

int ControlOrderDetails::poz1(int id)
{
	for (int i = 0; i < size; i++)
	{
		if (detail[i].getId() == id)
		{
			return i;
		}
	}
	return -1;
}

void ControlOrderDetails::Delete(int orderId)
{
	int p = poz(orderId);
	for (int i = p; i < size - 1; i++)
	{
		detail[i] = detail[i + 1] ;
	}
	size--;
}

void ControlOrderDetails::Delete2(int id)
{
	int p = poz1(id);

	for (int i = p; i < size - 1; i++)
	{
		detail[i] = detail[i + 1];
	}
	size--;
	
}

int ControlOrderDetails::nextId() {

	if (size == 0) {
		return 1;
	}

	return detail[size - 1].getId() + 1;
}

void ControlOrderDetails::updateOrderID(int orderId, int neworderId)
{
	int p = poz(orderId);
	if (p != -1)
	{
		detail[p].setorderId(neworderId);
	}
	else {
		cout << "Order Id not found" << endl;
	}
}

void ControlOrderDetails::updateProductId(int orderId, int newProductId)
{
	int p = poz(orderId);
	if (p != -1)
	{
		detail[p].setproductId(newProductId);
	}
	else
	{
		cout << "Product Id not found" << endl;
	}
}

void ControlOrderDetails::updatePrice(int orderId, int newPrice)
{
	int p = poz(orderId);
	if (p != -1)
	{
		detail[p].setPrice(newPrice);
	}
	else
	{
		cout << "The Price is wrong" << endl;
	}
}

void ControlOrderDetails::updateQuantity(int orderId, int newQuantity)
{
	int p = poz(orderId);
	if (p != -1)
	{
		detail[p].setQuantity(newQuantity);
	}
	else
	{
		cout << "Wrong quantity." << endl;
	}
}

OrderDetails ControlOrderDetails::get(string productName, int orderID)
{
	ControlProducts c;

	int productId = c.getProduct(productName).getId();

	for (int i = 0; i < size; i++)
	{
		if (productId == detail[i].getId() && detail[i].getorderId() == orderID)
		{
			return detail[i];
		}
	}

	return OrderDetails();
}

OrderDetails* ControlOrderDetails::getProducts(int orderId, int& number) {

	number = 0;
	OrderDetails* ordersDetails = new OrderDetails[100];

	for (int i = 0; i < size; i++) {

		if (detail[i].getorderId() == orderId) {

			ordersDetails[number] = detail[i];

			number++;
		}
	}

	return ordersDetails;
}

void ControlOrderDetails::load()
{
	ifstream read("orderdetails.txt");

	while (!read.eof())
	{

		int id;
		read >> id;
		int orderId;
		read >> orderId;
		int productId;
		read >> productId;
		int price;
		read >> price;
		int quantity;
		read >> quantity;

		if (id > 0) {

			OrderDetails g(id, orderId, productId, price, quantity);
			this->add(g);
		}

	}

	read.close();

}

string ControlOrderDetails::toSave()
{
	string text = "";
	int i = 0;
	for (i = 0; i < size-1; i++)
	{
		text += detail[i].toSave() + "\n";
	}

	text += detail[i].toSave();
	return text;
}

void ControlOrderDetails::save()
{
	ofstream f("orderdetails.txt");

	f << this->toSave();

	f.close();
}