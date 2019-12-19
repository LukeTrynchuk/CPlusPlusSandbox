#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private :
	String m_Name;
public:
	Entity() : m_Name("Unknown") {}
	Entity(const String& name) : m_Name(name) {}

	const String& GetName() const { return m_Name; }
};

int main()
{
	/*
	=====================INSTANTIATION=====================
	When we create an object in C++, we can control where
	the object is stored. 

	1.On stack. When we create on the stack, it is quick,
		we don't have to manage it, but it will be freed when
		it goes out of scope.

	2.On heap. When we create on the heap, it is a bit slower,
		we have to manage the memory and delete it, but it will
		not be freed when the variable goes out of scope.
	*/

	Entity entity("Luke");
	std::cout << entity.GetName() << std::endl;

	Entity* heapEntity = new Entity("Trynchuk");
	std::cout << heapEntity->GetName() << std::endl;

	delete heapEntity;
	std::cin.get();
}