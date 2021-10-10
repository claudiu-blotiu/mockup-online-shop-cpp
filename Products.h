#include <iostream>
#include<fstream>
#include<string>

using namespace std;
class Products
{
private:
	int id=1;
	string name = "";
	int weight = 1;
	int price = 1;
	int stock = 1;

public:

	Products()
	{

	}
	Products(int,string ,int ,int ,int );


	void setId(int);
	int getId();

	void setName(string);
	string getName();

	void setWeight(int);
	int getWeight();

	void setPrice(int);
	int getPrice();

	void setStock(int);
	int getStock();

	string description();

	string toSave();
};

