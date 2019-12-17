#include <iostream>

class Entity
{
public :
	float X, Y;

	void Init()
	{
		X = 0.0f;
		Y = 0.0f;
	}

	void Print()
	{
		std::cout << "(" << X << ", " << Y << ")" << std::endl;
	}
};


class Player : public Entity
{
public :

	Player()
	{
		X = 0.0f;
		Y = 0.0f;
	}

	Player(float x, float y)
	{
		X = x;
		Y = y;
	}
};

/*
======================INITIALIZATION======================
In other languages, when we create a basic data type such
as an int or float, the value is set to the default value
(typically 0 for numeric value).

In C++, you are responsible for setting the default value. 
When we create an int (as an example), the variable is 
assigned a memory address. The value of the variable can be
litterally anything, it value before it is initialized is just
whatever the bits happened to be when it was assigned the
address. Typically this is a very large number, but theoretically,
it could also be something small like 5.

It isn't until we assign a value that the bits found at the variable's
memory address are written to.

For classes, we have the option to write a constructor. A constructor
is a method that is run when the object is first created. If we 
don't specify a constructor, our classes are given a default constructor
which doesn't do anything. If we do write a constructor, we can 
place our data initialization there.

The "Entity" class is an example of a class without an initializer.
The "Player" class is an example of a class with an initializer.
*/

int main()
{
	//When we first create "e" it is uninitialized. The data members
	//inside have not yet been assigned a value. This is dangerous
	//and can cause unwanted behaviour. 
	//
	//Be wary though, calling any method from the function will cause
	//any compiler errors to disappear from the use of an uninitialized 
	//variable, however the issue is still present.
	Entity e;
	e.Init();
	e.Print();

	//Constructor sets "p" values.
	Player p = Player(2.0f, 3.0f);
	p.Print();

	std::cin.get();
}