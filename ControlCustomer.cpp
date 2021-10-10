#include "ControlCustomer.h"

ControlCustomer::ControlCustomer()
{
	load();
}

void ControlCustomer::add(Customer a)
{
	person[size] = a;
	size++;
}

void ControlCustomer::show()
{
	for (int i = 0; i < size; i++)
	{
		cout << person[i].description();
		cout << endl;
	}
}

int ControlCustomer::poz(string email)
{
	for (int i = 0; i < size; i++)
	{
		if (person[i].getEmail() == email)
		{
			return i;
		}
	}
	return -1;
}

void ControlCustomer::Delete(string email)
{
	int p = poz(email);
	for (int i = p; i < size - 1; i++)
	{
		person[i] = person[i +1];
	}
	size--;
	
}

int ControlCustomer::nextId()
{
	if (size == 0)
	{
		return 1;
	}

	return person[size-1].getId()+1;
}

void ControlCustomer::updateEmail(string email, string newEmail)
{
	int p = poz(email);
	if (p != -1)
	{
		person[p].setEmail(newEmail);
	}
	else {
		cout << "Wrong Email" << endl;
	}
}

void ControlCustomer::updatePassword(string email, string newPassword)
{
	int p = poz(email);

	if (p != -1)
	{
		person[p].setPassword(newPassword);
	}
	else {
		cout << "Email not found" << endl;
	}
}

void ControlCustomer::updateFullname(string email, string newFullname)
{
	int p = poz(email);
	if (p != -1)
	{
		person[p].setFullname(newFullname);
	}
	else {
		cout << "Email not found" << endl;
	}
}

void ControlCustomer::updateBillingadress(string email, string newBillingadress)
{
	int p = poz(email);
	if (p != -1)
	{
		person[p].setBillingadress(newBillingadress);
	}
	else {
		cout << "Email not found" << endl;
	}
}

void ControlCustomer::updateShippingadress(string email, string newShippingadress)
{
	int p = poz(email);
	if (p != -1)
	{
		person[p].setShippingAdress(newShippingadress);
	}
	else
	{
		cout << "Email not found";
	}
}

void ControlCustomer::updateCountry(string email, string newCountry)
{
	int p = poz(email);
	if (p != -1)
	{
		person[p].setCountry(newCountry);
	}
	else
	{
		cout << "Email not found" << endl;
	}
}

void ControlCustomer::updatePhone(string email, int newPhone)
{
	int p = poz(email);
	if (p != -1)
	{
		person[p].setPhone(newPhone);

	}
	else
	{
		cout << "Email not found" << endl;
	}
}

Customer ControlCustomer::getCustomer(string name)
{
	int pozitie = poz(name);

	return person[pozitie];

}

Customer ControlCustomer::getUser(string name, string parola)
{
	for (int i = 0; i < size; i++)
	{
		if (person[i].getFullname() == name && person[i].getPassword() == parola)
		{
			return person[i];
		}
	}
	return Customer();
}

void ControlCustomer::load()
{
	ifstream read("customer.txt");

	while (!read.eof())
	{
		int id;
		read >> id;
		string email;
		read >> email;
		string password;
		read >> password;
		string fullName;
		read >> fullName;
		string billingAdress;
		read >> billingAdress;
		string shippingAdress;
		read >> shippingAdress;
		string country;
		read >> country;
		int phone;
		read >> phone;

		Customer c(id, email, password, fullName, billingAdress, shippingAdress, country, phone);


		this->add(c);
	}
}

string ControlCustomer::toSave()
{
	string text = "";
	int i = 0;
	for (i=0; i < size-1; i++)
	{
		text += person[i].toSave() + "\n";
	}

	text += person[i].toSave();
	return text;

}

void ControlCustomer::save()
{
	ofstream f("customer.txt");

	f<<this->toSave();

	f.close();
}
