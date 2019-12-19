#include <iostream>

static int s_Level = 1;
static int s_Speed = 2;

int main()
{
	/*
	====================TERNARY OPERATOR===================
	Ternary operators allow us to condense simple if else 
	statements into one line.
	*/

	//This
	if (s_Level > 5)
		s_Speed = 10;
	else
		s_Speed = 5;

	//is equivalent to this
	s_Speed = (s_Level > 5) ? 10 : 5;

	std::cout << s_Speed << std::endl;
	std::cin.get();
}