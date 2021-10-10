#include "ViewUser.h"

string ViewUser::meniu()
{
	string text = "";
	text += "--------------------------------------";
	text += "\nApasati tasta 1 pentru a adauga produse in cos";
	text += "\nApasati tasta 2 pentru a elimina produse din cos";
	text += "\nApasati tasta 3 pentru a vedea produsele din cos";
	text += "\nApasati tasta 4 pentru a vedea toate produsele din magazin";
	text += "\nApasati tasta 5 pentru a cumpara ce este in cos";
	text += "\nApasati tasta 6 pentru a vedea istoricul comenzilor";
	text += "\nApasati tasta 0 pentru a iesii in meniu";
	text += "\n--------------------------------------";
	text += "\n";	

	return text;
}

void ViewUser::play()
{
	bool quit = false;
	int choise;

	while (quit == false)
	{	
		cout << meniu();

		string x;
		cin >> x;

		choise = stoi(x);

		switch (choise)
		{
		case 1:add();
			break;
		case 2:remove();
			break;
		case 3:viewCos();
			break;
		case 4:viewShop();
			break;
		case 5:buy();
			break;
		case 6:history();
			break;
		case 0:cout << "La revedere" << endl;
			break;
			
		}
	}
}

ViewUser::ViewUser(Customer c)
{
	this->customer = c;
	
	Order o(orders.nextId(), c.getId(), 0, c.getShippingAdress(), c.getBillingadress(), c.getEmail(),1, false);

	order = o;

}

void ViewUser::add()
{
	string name = "";

	cout << "Introduceti numele produsului." << endl;

	cin >> name;

	Products choise = products.getProduct(name);

	if (choise.getName() == name)
	{
		cout << "Introduceti cantitatea dorita" << endl;

		string cant;
		cin >> cant;

		int cantitate = stoi(cant);

		//verificam daca cantitatea exista 

		if (choise.getStock()>cantitate)
		{
			OrderDetails detalii(details.nextId(), order.getId(), choise.getId(), choise.getPrice() * cantitate, cantitate);
			details.add(detalii);
			products.updateStock(choise.getName(), choise.getStock() - cantitate);

		}
		else {
			cout << "Cantitatea introdusa nu este disponibila " << endl;
		}
	}
}

void ViewUser::viewShop()
{
	
	products.show();

}

void ViewUser::viewCos()
{

	int contor = 0;

	OrderDetails* produseDinCos = details.getProducts(order.getId(), contor);

	for (int i = 0; i < contor; i++) {

		Products p = products.getProduct1(produseDinCos[i].getproductId());

		string desc = "";

		desc += "Produs " + p.getName()+"\n";
		desc += "Pret total " + to_string(produseDinCos[i].getPrice())+"\n";
		desc += "Cantiate " + to_string(produseDinCos[i].getQuantity())+"\n";

		cout << desc << endl;
	}
}

void ViewUser::remove()
{
	string name = "";

	cout << "Introduceti numele produsului" << endl;

	cin >> name;

	int ct = 0;

	Products produse = products.getProduct(name);

	OrderDetails* produseDetaliate = details.getProducts(order.getId(), ct);

	for (int i = 0; i < ct; i++)
	{
		if (produseDetaliate[i].getproductId() == produse.getId())
		{
			details.Delete2(produseDetaliate[i].getId());
			products.updateStock(produse.getName(), produse.getStock() + produseDetaliate[i].getQuantity());
		}
	}
}

void ViewUser::buy()
{
	orders.add(order);

	orders.save();

	details.save();

	products.save();

}

void ViewUser::history()
{
	int ct = 0;

	Order* istoric = orders.getHistory(customer.getId(), ct);

	for (int i = 0; i < ct; i++)
	{
		cout << istoric[i].description() << endl;
	}
	
}

