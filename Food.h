#include"Products.h"

class Food:public Products
{
private:

	string type = "";

public:

	Food()
	{

	}

	Food(string, int, int, int, int);

	void set_type(string);
	string get_type();

	string description();

	string to_save();

};

