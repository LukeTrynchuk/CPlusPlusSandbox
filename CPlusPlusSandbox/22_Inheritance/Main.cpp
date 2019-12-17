#include <iostream>

class vec2
{
public:
	float x;
	float y;

	vec2(float _X, float _Y)
	{
		x = _X;
		y = _Y;
	}

	void Add(vec2 amount)
	{
		x += amount.x;
		y += amount.y;
	}
};

class Entity
{
public:
	vec2 position = vec2(0.0f, 0.0f);
	
	void Move(vec2 deltaMovement)
	{
		position.Add(deltaMovement);
	}
};

class Player : public Entity
{
public:
	const char* name;

	void PrintName()
	{
		std::cout << name << std::endl;
	}
};

/*
======================INHERITANCE=====================
Inheritance is the act of taking one class to be the 
base building block to build another. In the case 
of the "Player" class, we've made it inherit from
the "Entity" class. "Player" is now known as the 
"derived" class while "Entity" is the "base" class.

The derived class contains all the data members and 
methods that the base class has in addition to whatever
it may add as well.

Player could have been written like so : 

class Player
{
public:
	const char* name;
	vec2 position = vec2(0.0f, 0.0f);

	void PrintName()
	{
		std::cout << name << std::endl;
	}

	void Move(vec2 deltaMovement)
	{
		position.Add(deltaMovement);
	}
};

However, the "Entity" class has a number of functions 
and data members that we would like to use but maybe 
we don't want to write out again. This can help maintain
our classes and also create relations between classes:

Shape -> Circle -> Wheel -> Car Wheel -> Ford(C) F150 Wheel

When we create an instance of "Player", we can say that the
instance is of type "Player" and "Entity". We can say this
because the "Player" class is derived from the "Entity" class.

However, if we cast the an instance of Player to Entity, we will
not be able to access the Player specific data or methods.
See below :
*/

int main()
{
	//We can create a player and work with it using
	//both Player and Entity methods / data.
	Player player;
	player.Move(vec2(1, 10));
	player.name = "Player1";
	player.PrintName();

	//We create an entity pointer and give it
	//the address of our Player instance.
	//However, because the pointer is of type
	//entity, we can only access "Entity" data
	//and methods.
	Entity* entityPointer = &player;

	//Below would cause an error
	//*entityPointer.name = "Player2";

	std::cin.get();
}