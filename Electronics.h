#include"Toys.h"

class Electronics:public Products
{
private:

	string marca = "";

public:

	Electronics()
	{

	}

	Electronics(string, int, int, int, int);

	void set_marca(string);
	string get_marca();

	string description();

	string to_save();
};

