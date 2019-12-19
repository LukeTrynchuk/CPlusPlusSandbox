#include <iostream>

class Entity
{
private:
	std::string m_Name;
	mutable int class_count = 0;

public:
	//returns a string reference that is immutable (not changable or const)
	//And the method promises not to modify any data members.
	const std::string& GetName() const
	{
		static int static_count = 0;
		static_count++;

		class_count++;

		return m_Name;
	}
};

int main()
{
	/*
	==================MUTABLE================
	The mutable key word declares that something
	is allowed to be modified and changed. You
	will use the mutable keyword in two main ways:

	1. In classes, if we declare a data member as 
		mutable, then it may be modified in any
		const function.

	2. In lambda expressions, we can declare a 
		lambda to be mutable and then we can modify
		any values we pass in.
	*/

	int x = 8;
	auto f = [=]() mutable
	{
		x++;
		std::cout << x << std::endl;
	};

	f();

	std::cin.get();
}