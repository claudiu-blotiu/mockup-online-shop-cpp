#include"ControlCustomer.h"

class ViewUser
{
private:
	Customer customer;
	ControlProducts products;
	ControlOrderDetails details;
	ControlOrder orders;
	Order order;

public:
	
	ViewUser(Customer c);


	string meniu();

	void play();

	void add();

	void viewShop();

	void viewCos();

	void remove();

	void buy();

	void history();
};

