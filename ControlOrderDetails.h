#include "OrderDetails.h"
class ControlOrderDetails
{
private:
	OrderDetails detail[100];
	int size = 0;
public:
	ControlOrderDetails();

	void add(OrderDetails a);

	void show();

	int poz(int orderId);

	int poz1(int id);

	void Delete(int orderId);

	void Delete2(int id);

	int nextId();

	void updateOrderID(int orderId, int newOrderId);

	void updateProductId(int orderId, int newProductId);

	void updatePrice(int orderId, int newPrice);

	void updateQuantity(int orderId, int newQuantity);

	OrderDetails get(string name, int orderId);

	OrderDetails* getProducts(int orderId, int& number);

	void load();

	string toSave();

	void save();




	

};

