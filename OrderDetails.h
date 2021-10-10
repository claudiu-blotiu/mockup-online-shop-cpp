#include"ControlProducts.h"

class OrderDetails
{
private:
	int id=1;
	int orderId=1;
	int productId=1;
	int price = 1;
	int quantity = 1;
public:
	OrderDetails()
	{

	}
	OrderDetails(int, int, int, int, int);

	void setId(int);
	int getId();

	void setorderId(int);
	int getorderId();

	void setproductId(int);
	int getproductId();

	void setPrice(int);
	int getPrice();

	void setQuantity(int);
	int getQuantity();

	string description();

	string toSave();
	
};

