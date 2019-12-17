#include <iostream>

/*
==================DESTRUCTORS===================
Similar to how a constructor runs when an object
is created, a destructor runs when an object is 
being destroyed. This is super handy for cleaning
up any memory and avoid memory leaks.
*/

struct vec2
{
	float x;
	float y;

	vec2()
	{
		std::cout << "Created vec2" << std::endl;
		x = 0.0f;
		y = 0.0f;
	}

	vec2(float _X, float _Y)
	{
		std::cout << "Created vec2" << std::endl;
		x = _X;
		y = _Y;
	}

	~vec2()
	{
		std::cout << "Destroyed vec2" << std::endl;
	}

	void Print()
	{
		std::cout << "(" << x << "," << y << ")" << std::endl;
	}
};

class Entity
{
public:

	vec2 position = vec2(0.0f, 0.0f);

	Entity()
	{
		std::cout << "Created Entity" << std::endl;
		position.x = 0.0f;
		position.y = 0.0f;
	}

	Entity(float x, float y)
	{
		std::cout << "Created Entity" << std::endl;
		position.x = x;
		position.y = y;
	}

	~Entity()
	{
		std::cout << "Destroyed Entity" << std::endl;
	}

	void Print() 
	{
		position.Print();
	}
};

void Function()
{
	Entity e;
	e.Print();
}

int main()
{
	Function();

	std::cin.get();
}