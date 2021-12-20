#include"Food.h"

class Toys:public Products
{
private:

	int minimAge = 0;

public:

	Toys()
	{

	}

	Toys(int, int, int, int, int);

	void set_minimAge(int);
	int get_minimAge();

	string description();

	string to_save();


};

