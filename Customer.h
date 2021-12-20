#include "ControlOrder.h"
class Customer
{
private:
	int id = 1;
	string email = "";
	string password = "";
	string fullName = "";
	string billingAdress = "";
	string shippingAdress = "";
	string country = "";
	int phone = 1;
public:
	Customer()
	{

	}
	Customer(int, string, string, string, string, string, string, int);

	void setId(int);
	int getId();

	void setEmail(string);
	string getEmail();

	void setPassword(string);
	string getPassword();

	void setFullname(string);
	string getFullname();

	void setBillingadress(string);
	string getBillingadress();

	void setShippingAdress(string);
	string getShippingAdress();

	void setCountry(string);
	string getCountry();

	void setPhone(int);
	int getPhone();

	string description();

	string toSave();
};

