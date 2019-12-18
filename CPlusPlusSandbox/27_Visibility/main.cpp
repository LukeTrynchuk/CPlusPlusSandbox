#include <iostream>

/*
==================VISIBILITY=================
Visibility refers to the availability of methods
and data members from classes. We can use three
levels of visibility : 

* public
* private
* protected

When a data member or method is declared public,
it means that any other class or function can
access it.

When a data member or method is declared private,
no other class or function can access it.

When a data member or method is declared protected,
only itself and derived classes can access it.
*/

class Entity
{
public:
	Entity()
	{
		X = 0.0f;
		Y = 0.0f;
	}

protected:
	void SetPosition(float _x, float _y);

private :
	float X, Y;

};

//Has access to SetPosition() but not X or Y
class Player : public Entity
{
public:
	Player()
	{

	}
};

int main()
{
	//Has access to neither SetPosition() or X or Y.

	std::cin.get();
}