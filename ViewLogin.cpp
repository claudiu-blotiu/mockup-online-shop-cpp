#include "ViewLogin.h"

string ViewLogin::meniu()
{
	string text = "";

	text += "-----------------------------------------";
	text += "\nApasati tasta 1 pentru Logare";
	text += "\nApasati tasta 2 pentru Inregistrare";
	text += "\nApasati tasta 3 pentru Delogare";
	text += "\n-----------------------------------------";
	text += "\n";

	return text;
}

void ViewLogin::play()
{
	bool quit = false;
	int choise;

	if (quit == false)
	{
		cout << meniu();

		string x;
		cin >> x;

		choise = stoi(x);

		switch (choise)
		{
		case 1:login();
			break;

		case 2:inregistrare();
			break;
		}
	}
}

ViewLogin::ViewLogin()
{
	this->customers = new ControlCustomer();
}

void ViewLogin::login()
{
	string user = "";

	cout << "Introduceti Username" << endl;

	cin >> user;

	string parola = "";

	cout << "Introduceti parola" << endl;

	cin >> parola;

	
	Customer* c = customers->getUser(user, parola);

	if (c->getFullname() == user)
	{

		ViewUser* view = new ViewUser(c);
		
		view->play();
	}
	else
	{
		cout << "Wrong Username or password" << endl;
	}
}

void ViewLogin::inregistrare()
{
	string email = "";
	cout << "Introduceti Emailul dorit" << endl;
	cin >> email;

	string parola = "";
	cout << "Introduceti parola dorita" << endl;
	cin >> parola;

	string user = "";
	cout << "Introduceti Username dorit" << endl;
	cin >> user;

	string facturare = "";
	cout << "Introduceti adresa de facturare dorita" << endl;
	cin >> facturare;

	string livrare = "";
	cout << "Introduceti adresa de livrare dorita" << endl;
	cin >> livrare;

	string tara = "";
	cout << "Introduceti tara dorita" << endl;
	cin >> tara;

	int telefon = 1;
	cout << "Introduceti nr de telefon dorit" << endl;
	cin >> telefon;

	
	Customer* a=new Customer(customers->nextId(), email, parola, user, facturare, livrare, tara, telefon);
	customers->add(a);
	
	customers->save();
}

