#include <iostream>
#include <string>

/*
======================INITIALIZER LISTS======================
Initializer lists are a way to initialize data members in 
classes. Previously, we've been initializing each data member
individually in a constructor. However, we can write our 
constructors so that we initialize the data outside of
the braces of the function. See example down below.
*/

class Entity
{
private :
	std::string m_Name;
	int m_Score;

public:
	Entity()
		: m_Name("Unknown"), m_Score(0)
	{
	}

	Entity(const std::string& name)
	{
		m_Name = name;
	}

	const std::string& GetName() const { return m_Name; }
	const int& GetScore() const { return m_Score; }
};

/*
An added benefit of using initializer lists, is that when we
use an initializer list, the data is only initialized once. If
we initialize individually, the data is initialized once when the
object is created and once again in the constructor.
*/

int main()
{
	Entity e0;
	std::cout << e0.GetName() << std::endl;

	Entity e1 = Entity("Luke");
	std::cout << e1.GetName() << std::endl;

	std::cin.get();
}