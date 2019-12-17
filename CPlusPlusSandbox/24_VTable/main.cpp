#include <iostream>

class RegularClass
{
	int i;
};

class VirtualBaseClass
{
	int i;
	virtual void Func();
};

class VirtualDerivedClass : VirtualBaseClass
{
	int j;
	void Func() override {}
};

int main()
{
	/*
	=====================V TABLE===================
	When we use virtual functions in our class structure
	an invisible pointer is added. If you remember, a pointer
	is just an int. An int is 4 bytes. We can confirm this 
	by printing out the size of certain classes : 
	*/

	std::cout << "Regular Class : " << sizeof(RegularClass) << std::endl;
	std::cout << "Virtual Base Class : " << sizeof(VirtualBaseClass) << std::endl;
	std::cout << "Virtual Derived Class : " << sizeof(VirtualDerivedClass) << std::endl;

	/*
	When we use virtual functions, a table must be created that
	stores the indirection needed to allow for dynamic binding of
	functions. This is similar to the Page Table (project #17).

	Each class that contains a virtual function must have a pointer
	that points to the table. When the object uses the virtual function,
	the pointer to the v table (v pointer) is used. The table is searched
	for the correct implementation to use. 

	This of course all comes at a cost.

	1. Size
		Each class that uses a virtual function will need a v pointer.
		The v pointer may add additional size to the class depending on
		byte padding.

	2. Execution time
		Looking up a table is not free. Though it may not have a noticable
		impact on your performance, it is there. If you are writting a 
		performance critical application, you may want to be aware of the
		extra hidden cost of calling virtual functions. Though, in most cases
		it won't cause any trouble. If we don't have to look up a v table, 
		then the execution of the function is immediate.
	*/

	std::cin.get();
}