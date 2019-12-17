#include <iostream>

/*
===============LOCAL STATIC================
Static variables found inside a structure
(function, if statement, switch statement, etc..)
are not destroyed when the variable becomes out of scope.
The data in the memory address still retains the
same value. If and when the variable were to be
created again, the memory address is read and the
value is reassigned the the variable.

The below Function() instantiates a variable, increments
it and then when it becomes out of scope, the variable is
destroyed. When Function() is called again, the same value 
will be calculated.

StaticFunction() however, contains a static variable. The
static variable is not visible outside of the scope of the
function but the data at the memory address will not be lost
and so each time the function is executed, the value found at 
that memory address will increment.
*/
void Function()
{
	int i = 0;
	i++;
	std::cout << i << std::endl;
}


void StaticFunction()
{
	static int i = 0;
	i++;
	std::cout << i << std::endl;
}

int main()
{
	Function();
	Function();
	Function();
	Function();
	Function();

	StaticFunction();
	StaticFunction();
	StaticFunction();
	StaticFunction();
	StaticFunction();

	std::cin.get();
}