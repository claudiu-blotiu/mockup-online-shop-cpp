#include"Electronics.h"

class ControlProducts
{
private:
	Products** product;
	
public:

	int size = 0;

	ControlProducts();

	void add(Products* a);

	void show();

	int poz(string name);

	void Delete(string name);

	int nextId();

	void updateName(string name, string newName);

	void updateWeight(string name, int newWeight);

	void updatePrice(string name, int newPrice);

	void updateStock(string name, int newStock);

	Products* getProduct(string name);

	Products* getProduct1(int productId);

	void load();

	string toSave();

	void save();
};

