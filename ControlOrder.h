#include "order.h"
class ControlOrder
{
private:
	Order** list;
	int size = 0;
public:
	ControlOrder();

	void add(Order* a);

	void show();

	int poz(int customerId);

	void Delete(int customerId);

	int nextId();

	void updatecustomerId(int customerId, int newCustomerId);

	void updateAmmount(int customerId, int newAmmount);

	void updateShippingAdress(int customerId, string newShippingAdress);

	void updateOrderAdress(int customerId, string newOrderAdress);

	void updateOrderEmail(int customerId, string newOrderEmail);

	void updateOrderDate(int customerId, int newOrderDate);

	void updateOrderStatus(int customerId, bool newOrderStatus);

	Order* getHistory(int customerId, int& nr);

	void load();

	string toSave();

	void save();

};

