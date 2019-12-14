#include "Log.h"
#include <iostream>

/*
	Be careful! If you include more than one
	implementation of a function, then you will
	be met with a linker error (for more on the
	linker see 2_HelloWorldWithMethod).

	LNK1169: one or more multiply defined symbols found

	If the below code were to be uncommented out,
	the linker would like two Log() functions and
	wouldn't know which version to use. 

	For ease of use and understanding, it is 
	best practice to use paired files.

	Player.h functions are found in Player.cpp
	Enemy.h functions are found in Enemy.cpp
	Inventory.h functions are found in Inventory.cpp
	etc...
*/


//void Log(const char* message)
//{
//	std::cout << message << std::endl;
//}