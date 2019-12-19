#include <iostream>

class Entity
{
private:
	int* m_X;
	int* m_Y;
	mutable int* m_Z;
public:

	//This method promises not to modify any data members
	int* GetX() const
	{
		//mutable data members are okay though
		*m_Z = 2;
		return m_X;
	}

	//This method promises not to modify any data members
	//and will return a pointer that cannot modify the value
	//found at the address it points to, and cannot change 
	//what it points to. This is a great way to ensure safety
	//with getters.
	const int* const GetY() const
	{
		return m_Y;
	}
};

//Function takes in an int* that will not be able
//to modify the contents or what it points to.
//Any int* can be passed into it, not just pointers
//that are const int* const
void Function(const int* const value)
{
	std::cout << *value << std::endl;
}

int main()
{
	/*
	====================CONST================
	When we declare a variable to be const, we
	are telling the compiler that we will not
	change the value of that variable. 

	If we try to change it, we will get an 
	error.
	*/

	//Cannot be changed.
	const int MAX_AGE = 100;
	std::cout << MAX_AGE << std::endl;

	//But we can technically get around it
	//but it's not recommended.

	int* ptr = (int*)&MAX_AGE;
	*ptr = -34;

	//MAX_AGE returns the original value, but the memory says otherwise
	std::cout << MAX_AGE << std::endl;
	std::cout << *ptr << std::endl;
	Function(ptr);

	//If we declare a pointer to be const, we cannot change the 
	//value of what it points to, however we can change what it
	//points to.
	const int* agePointer = (int*)&MAX_AGE;

	//If we put the const after the pointer, we are declaring that
	//the pointer can change the value of the variable it points
	//to, but we cannot change what it points to.
	int* const agePointer2 = (int*)&MAX_AGE;

	//Below refers to a pointer that cannot change the value that
	//it points to and cannot change what it points to.
	const int* const agePointer3 = (int*)&MAX_AGE;

	/*
	One other way to use the const keyword is after the name of a 
	function in a class (as shown above).

	When a function is declared const, it means that the function 
	cannot modify any data members of the class.
	*/

	std::cin.get();
}