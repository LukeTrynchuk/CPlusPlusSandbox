#include <iostream>

int main()
{
	/*
	=================POINTERS==============

	Pointers can be complex but they are 
	actually very simple (Don't overthink it).

	A pointer is an integer. The value it stores 
	is a memory address. 


	Below is an example of a pointer. Note that
	the type given (in this case is of type void)
	only refers to the type of data the is stored
	in the memory address that the pointer points 
	to.

	Remember, a pointer is an integer that contains
	a memory address, not the actual data stored at
	that memory address.

	In the case of the pointer below, we have set it
	to 0. Zero (0) is not a valid memory adress. This
	is equivalent to setting a reference type to null.

	Alternatively we could have written : 

	void* ptr = NULL;

	NULL is just 
	#define NULL 0

	or

	We could have written :

	void* ptr = nullptr;

	Notice the asterisk (*) that appears after the type.
	This denotes that the following variable is a pointer.
	*/
	void* ptr = 0;

	/*
	Below is an integer. However, this is an actual
	variable that contains data. If we looked at the
	memory address of "var", we would find the bits 
	that represent 8.
	*/
	int var = 8;

	/*
	We can find the memory address of a particular 
	variable by placing the & symbol directly before
	the variable. Below is an example of printing
	the address of "var".
	*/

	std::cout << &var << std::endl;

	/*
	You should note that the given memory address 
	is not reliably the same every time. The computer
	is a very complex machine and will give a variable
	an address to occupy, but will not always give the
	same value to the same variable every time. 

	Below is an example of how we can store the memory
	address of one variable inside our pointer.
	*/

	ptr = &var;

	/*
	You'll notice, if you print out the pointer you'll
	get the address of "var". Because a pointer is only
	storing the memory address of some variable.
	*/

	std::cout << ptr << std::endl;

	/*
	When we declared our pointer above, we gave it
	the type of void.

	void* ptr = 0;

	Even though we can store the memory address of 
	of type in a pointer, the type of the pointer
	refers to the type of data the will be constructed
	out of the memory address if we would like to 
	get access to whatever is at the address. 

	We can't actually modify the value of var through
	our pointer because "ptr" beleives that the data
	type stored at the memory address it points to
	is of type void.

	Let's make a new pointer of type int.
	*/
	int* intPointer = &var;

	/*
	If we would now like to access the memory that
	"intPointer" points to, we need to dereference
	the pointer. This is done with the asterisk (*)
	*/

	*intPointer = 10;

	/*
	Now the memory that "intPointer" points to contains
	the bits that represent the value of 10. We can verify
	this by printing "var".
	*/
	std::cout << var << std::endl;

	/*
	You may come across instances of double pointers.
	A double pointer is a pointer that points to
	the memory address of another pointer.

	Let's make one now.

	"doublePointer" is a pointer that points to the
	memory address of "intPointer". We set it equal to
	the memory address of "intPointer" by using the 
	& symbol directly infront of the variable name.
	*/
	int** doublePointer = &intPointer;


	/*
	Similarly, we can also access the memory at that
	location using two asterisk (**). Which makes
	sense because if we only dereference once then 
	we are getting "intPointer". If we dereference
	a second time then we get the value of the memory
	that "intPointer" refers to.
	*/
	**doublePointer = 20;
	std::cout << var << std::endl;

	/*
	This can actually scale to be much larger than 
	just 2 pointers in. However, you should really 
	never need more than a double pointer in 99.999%
	of all use-cases.
	*/
	int*** triplePointer = &doublePointer;
	int**** quadruplePointer = &triplePointer;
	int***** quintuplePointer = &quadruplePointer;

	*****quintuplePointer = 50;

	std::cout << var << std::endl;

	std::cin.get();
}