#include <iostream>

void Log(const char* message)
{
	std::cout << message << std::endl;
}

void main()
{
	//Will execute 5 times.
	//
	//Prints 5 times.
	for (int i = 0; i < 5; i++)
	{
		Log("Hello World!");
	}

	//Will execute 5 times, but when i == 3, 
	//will skip rest of execution of loop and 
	//back to conditional at top.
	//
	//Prints 4 times.
	for (int i = 0; i < 5; i++)
	{
		if (i == 3) continue;
		Log("Hello World!");
	}

	//Will execute 4 times. When 
	//i == 3 then the loop will break
	//and execution will continue outside of the loop
	//in this case line 40 and beyond.
	//
	//Prints 3 times
	for (int i = 0; i < 5; i++)
	{
		if (i == 3) break;
		Log("Hello World!");
	}
}