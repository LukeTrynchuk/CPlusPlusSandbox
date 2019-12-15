#include <iostream>

void Increment(int value)
{
	value++;
}

void IncrementPointer(int* value)
{
	//Be careful to dereference before incrementing!!
	(*value)++;
}

void IncrementReference(int& value)
{
	value++;
}

int main()
{
	/*
	===============REFERENCES================
	References are very similar to pointers,
	however, references must be bound to a
	particular variable. Unlike a pointer,
	you can't reference a null memory address.

	The way that we declare references are also
	slightly different. We use the & symbol next
	to the type as opposed to the asterisk (*) that
	we use in a pointer.

	Notice how the reference is set to the variable
	and not the variable's memory address, like how
	it is in a pointer.

	When a reference is created, it is said to have
	an alias to the variable. The reference can be
	used as though it were the variable. Any changes
	made to the reference will occure to the referenced
	variable as well.
	*/

	int a = 5;
	std::cout << a << std::endl;

	int& ref = a;
	int* ptr = &a;

	/*
	We can now modify the value of "a" through the
	reference.
	*/

	ref = 10;
	std::cout << a << std::endl;

	/*
	Now, what if we modify the value of "a" through
	a method such as the above Increment() method.

	The value of "a" will be copied to the method
	and the copied variable will be incremented. But
	the value of "a" will not actually change.
	*/

	Increment(a);
	std::cout << a << std::endl;

	/*
	If we wanted the value of "a" to retain the
	changes made in the method, we could pass the
	memory address of "a" and change the value
	found at the memory address.

	We can use the above method IncrementPointer();
	*/
	IncrementPointer(&a);
	std::cout << a << std::endl;

	/*
	Alternatively, we could change the value of
	"a" through the use of references. This works 
	because unlike Increment() where we pass a copy
	of "a" to a function, we are passing a reference.
	When a reference is created, it almost becomes a
	clone of the variable. When we change the value
	of the reference, we are actually changing that 
	value of the memory found at "a".

	We can use the above method IncrementReference();
	*/
	IncrementReference(a);
	std::cout << a << std::endl;

	/*
	============REFERENCES VS POINTERS==============
	Beyond some slightly different syntax, here are
	some more differences between pointers and 
	references

	1. Pointers can change what they are pointing to
	as many times as you'd like. However, references
	cannot change what they are referencing once they've
	been set.

	2. References share the same memory address as the
	referenced variable, while a pointer has a separate 
	memory address separate from the memory it is pointing
	to.

	3. Pointers can be null, while references MUST reference
	some variable (even if the value of the variable is null).
	*/

	std::cin.get();
}