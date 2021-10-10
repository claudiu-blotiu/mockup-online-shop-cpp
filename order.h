#include "ControlOrderDetails.h"
class Order
{
private:
	int id=1;
	int customerId = 1;
	int ammount = 1;
	string shippingAdress = "";
	string orderAdress = "";
	string orderEmail = "";
	int orderDate = 1;
	bool orderStatus = true;
public:
	Order()
	{

	}

	Order(int, int, int, string, string, string, int, bool);

	void setId(int);
	int getId();

	void setcumstomerID(int);
	int getcustomerId();

	void setammount(int);
	int getammount();

	void setshippingAdress(string);
	string getshippingAdress();

	void setorderAdress(string);
	string getorderAdress();

	void setorderEmail(string);
	string getorderEmail();

	void setorderDate(int);
	int getorderDate();

	void setorderStatus(bool);
	bool getorderStatus();

	string description();

	string toSave();
};

