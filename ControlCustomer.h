#include"Customer.h"
class ControlCustomer
{
private:
	Customer** person;
	int size = 0;
public:
	ControlCustomer();

	void add(Customer* a);

	void show();

	int poz(string email);

	void Delete(string email);

	int nextId();
	
	void updateEmail(string email,string newEmail);

	void updatePassword(string email, string newPassword);

	void updateFullname(string email, string newFullname);

	void updateBillingadress(string email, string newBillingadress);

	void updateShippingadress(string email, string newShippingadress);

	void updateCountry(string email, string newCountry);

	void updatePhone(string email, int newPhone);

	Customer* getCustomer(string name);

	Customer* getUser(string name, string parola);

	void load();

	string toSave();

	void save();
};

