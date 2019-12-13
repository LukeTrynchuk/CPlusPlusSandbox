#include <iostream>

/*
	===========DATA=============
	Variables store data at different unique locations
	in memory. The data uses bits to store the value
	regardless of the data type.

	int uses 4 bytes.

	1 byte is made up of 8 bits.

	A bit can be either 0 or 1. On or off.

	Bits are the smallest data building block. In
	total, an int takes up 32 bits to store a value
	using powers of 2 (with one bit to determine the 
	sign of the value).

	An int then in total uses 1 bit for the sign and
	31 bits for the value. That makes the highest possible
	number that can be stored 2^31 or 2,147,483,648.
*/

int main()
{
	//interger 4 bytes large
	//Signed integer can store approximately -2billion to +2billion
	std::cout << "==========int==========" << std::endl;
	int variable = 8;

	std::cout << variable << std::endl;

	//Reassign value to pre-existing variable
	variable = 20;
	std::cout << variable << std::endl << std::endl;

	//Unsigned does not a bit to declare the sign,
	//therefore the total possible range of an unsigned
	//int is 0 to 2^32.
	std::cout << "======unsigned int======" << std::endl;
	unsigned int x = 2000;

	std::cout << x << std::endl << std::endl;

	/*
		Other possible integer types are :
		char		-		1 byte
		short		-		2 bytes
		int			-		4 bytes
		long		-		4 bytes (depending on compiler)
		long long	-		8 bytes

		the unsigned keyword can be applied to any
		of the integer type variables.
	*/

	/*
		Although char is an integer type 
		variable, a letter may be assigned as 
		opposed to a number. Letters are represented
		using a table of key value pairs (in this case 65). 
		An example of this chart can be found at : 

		https://en.cppreference.com/w/cpp/language/ascii

		The char data type is, for the most part used
		primarily to represent alphabetic characters.

		When we print out a char, the associated character
		is printed out instead of the numeric ASCII value.
	*/
	std::cout << "==========char==========" << std::endl;
	char c = 'A';
	std::cout << c << std::endl;

	c = 65;
	std::cout << c << std::endl;


	/*
		Despite this, we can still use chars for integer 
		based work. In this case the result is 40, however,
		"(" is printed out instead because "(" is 40 on the 
		ascii table.
	*/
	char otherChar = 25;
	c = c - otherChar;
	std::cout << c << std::endl << std::endl;

	//The reverse works too!
	std::cout << "==========short==========" << std::endl;
	short myShort = 'A';
	std::cout << myShort << std::endl << std::endl;

	/*
		Floating point types are numeric types
		that store values with decimals. Values
		such as 4.23 or 3.14, etc...

		Available types are : 
		float		:		4 bytes
		double		:		8 bytes
	*/

	std::cout << "=========float=========" << std::endl;
	float pi = 3.14f;
	std::cout << pi << std::endl << std::endl;

	std::cout << "========double========" << std::endl;
	double myDouble = 8.876;
	std::cout << myDouble << std::endl << std::endl;

	/*
		Booleans contain one of two values
		true or false. Similar to how you can
		use characters when assigning integer 
		types, you can also use 1(true) or 0(false)
		when assigning a bool.

		bool		:		1 byte

		Even though to store a bool value you only
		need on bit, we can only read as little as
		1 byte at a time. 
	*/
	std::cout << "==========bool==========" << std::endl;
	bool finished = 0;
	std::cout << finished << std::endl;
	finished = true;
	std::cout << finished << std::endl << std::endl;

	//Sizes : 
	std::cout << "==========sizes==========" << std::endl;
	std::cout << "Size of int " << sizeof(int) << std::endl;
	std::cout << "Size of char " << sizeof(char) << std::endl;
	std::cout << "Size of short " << sizeof(short) << std::endl;
	std::cout << "Size of long " << sizeof(long) << std::endl;
	std::cout << "Size of long long " << sizeof(long long) << std::endl;
	std::cout << "Size of float " << sizeof(float) << std::endl;
	std::cout << "Size of double " << sizeof(double) << std::endl;
	std::cout << "Size of bool " << sizeof(bool) << std::endl;

	std::cin.get();

	return 0;
}