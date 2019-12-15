/*
==================STATIC================
The static keyword has three meaning depending
on the context that it is written in.

1. Used to define a function outside of
a class. If it is used to define a function
outside of a class, then the function will only
be visible to the translation unit that it is
written in. Similarilly, a static variable outside
of a class will only exist inside a single
translation unit.

2. If it is used to define a data member of a
class. Then no matter how many instances of a particular
class there are, each instance with a static
data member will reference the same memory address.
This means that when we modify the value of
the static data member, then the value will
be the same for all the instances.

3. If it is used to define a function inside of
a class, then the function can be used without
an instance of the class. However, the function
will not have access to entity specific data.

*/

#include <iostream>

class Log
{
public:
	const int LogLevelError = 0;
	const int LogLevelWarning = 1;
	const int LogLevelInfo = 2;

private:
	int m_logLevel = LogLevelInfo;

public:
	void SetLevel(int level)
	{
		m_logLevel = level;
	}

	void Error(const char* message)
	{
		if (m_logLevel >= LogLevelError)
			std::cout << "[ERROR]: " << message << std::endl;
	}

	void Warn(const char* message)
	{
		if (m_logLevel >= LogLevelWarning)
			std::cout << "[WARNING]: " << message << std::endl;
	}

	void Info(const char* message)
	{
		if (m_logLevel >= LogLevelInfo)
			std::cout << "[INFO]: " << message << std::endl;
	}
};

//This will not have any issues with the variable of the
//same name in Static.cpp, because the variable of the
//same name is static and therefor only visible to the 
//translation unit is in.
int s_Variable = 10;

/*
The extern keyword means that this variable will look
for the same named variable in other translation units
other than this one. When it finds it, it will reference
that variable. 

If no external symbol matching globalVariable is found,
we will receive a linker error.
*/
extern int globalVariable;

int main()
{
	std::cout << s_Variable << std::endl;
	std::cout << globalVariable << std::endl;

	std::cin.get();
}