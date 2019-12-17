#include <iostream>

class A
{
public:
	void Print()
	{
		std::cout << "A" << std::endl;
	}
};

class B : public A
{
public :
	void Print()
	{
		std::cout << "B" << std::endl;
	}
};

class C
{
public:
	virtual void Print()
	{
		std::cout << "C" << std::endl;
	}
};

class D : public C
{
public:
	void Print() override
	{
		std::cout << "D" << std::endl;
	}
};

void PrintA(A a)
{
	a.Print();
}

void PrintC(C c)
{
	c.Print();
}

void PrintC1(C &c)
{
	c.Print();
}

void PrintC2(C* c)
{
	c->Print();
}

int main()
{
	/*
	====================VIRTUAL FUNCTIONS======================
	When we use inheritance we can create methods in the derived
	class of the same name. When we call that method, the derived
	class's method is what will be executed, not the base class's. 
	As shown below:
	*/

	B _b;
	_b.Print(); //B

	/*
	However, as described in the previous project, when a derived
	class is casted as the base type, only base type data and methods
	will be available. This is known as "object slicing".
	As shown below:
	*/
	PrintA(_b); //A

	/*
	Depending on your situation, this may be the desired behaviour.
	However, what if we would like to be able to cast to the base but
	still retain the behaviour of the derived?

	Enter Virtual Functions.

	We can mark certain functions in the base as virtual and override them
	in the derived. The derived class when casted the base will still execute
	the derived class's version of the method.

	As shown below:
	*/
	D _d;
	PrintC(_d); //C

	/*
	Eh, not quite. Remember how functions work by default. When we pass in a 
	parameter, the function will make a copy of the parameter passed in. It
	is not the same variable or the same memory address that we are manipulating.

	It is just a copy. Object slicing still occurs because the function is constructing
	a variable of the base type, not the derived type.

	However, as shown below, if we pass by reference, we get a different result.
	*/

	PrintC1(_d); //D

	//This works with pointers too.

	D* ptr = &_d;
	PrintC2(ptr);

	/*
	The reason the pointer and the reference work is because the function
	is using the data found at our memory address, in this case, it is of type
	"D".
	*/

	std::cin.get();
}