#include <iostream>

class IWeapon
{
public :
	virtual void DoDamage() = NULL;
};

class Sword : public IWeapon
{
public:
	void DoDamage() override
	{
		std::cout << "Did 8 points of melee damage" << std::endl;
	}
};

class Bow : public IWeapon
{
public :
	void DoDamage() override
	{
		std::cout << "Did 3 points of ranged damage" << std::endl;
	}
};

int main()
{
	/*
	===================INTERFACES====================
	Interfaces are a concept found in other languages.
	Interfaces are collections of function definitions
	without implementations that must have concrete
	implementations in the derived class.

	In the case of C++, we don't have interfaces, however
	we can have interface functionality through the use
	of pure virtual functions.

	When we create a class that has a pure virtual function,
	we cannot instantiate an instance of that class (because there
	is no implementation).

	This is infinitely useful, because it allows us to
	abstract away implementations and allows for more
	code flexibility.

	It is the convention to start the name of an interface with
	the preface "I".
	*/
	IWeapon* weapon = &Sword();
	weapon->DoDamage();

	weapon = &Bow();
	weapon->DoDamage();

	std::cin.get();
}