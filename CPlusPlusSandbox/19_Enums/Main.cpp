#include <iostream>

/*
===============ENUMS==============
Enums are a way to disguise integer
values as human readable identifiers.
*/

//enums are 32 bit integers by default
enum Example
{
	A,B,C
};

//However, we can assign a different type
enum ClassType : unsigned char
{
	WARRIOR, WIZARD, ARCHER
};

//We can also set the int value of each entry
enum WeaponType : unsigned char
{
	SWORD = 0,
	STAFF = 10,
	BOW = 30
};

int main()
{
	Example value = B;

	if (value == B)
	{
		std::cout << "B!" << std::endl;
	}

	std::cin.get();
}