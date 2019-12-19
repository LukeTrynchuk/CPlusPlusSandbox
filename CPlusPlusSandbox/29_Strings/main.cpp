#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <cmath>

class Timer
{
public:
	void start()
	{
		m_StartTime = std::chrono::system_clock::now();
		m_bRunning = true;
	}

	void stop()
	{
		m_EndTime = std::chrono::system_clock::now();
		m_bRunning = false;
	}

	double elapsedMilliseconds()
	{
		std::chrono::time_point<std::chrono::system_clock> endTime;

		if (m_bRunning)
		{
			endTime = std::chrono::system_clock::now();
		}
		else
		{
			endTime = m_EndTime;
		}

		return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_StartTime).count();
	}

	double elapsedSeconds()
	{
		return elapsedMilliseconds() / 1000.0;
	}

private:
	std::chrono::time_point<std::chrono::system_clock> m_StartTime;
	std::chrono::time_point<std::chrono::system_clock> m_EndTime;
	bool                                               m_bRunning = false;
};


int main()
{
	/*
	================STRINGS================
	Strings are variables that contain characters.
	These are typically how we represent text.

	Strings are used to represent things like names,
	bodies of text, etc..

	So far, we've only used the C style string:
	*/

	/*
	Building on the previous project, strings, or
	const char* is just an array of chars (1 byte each).
	*/
	
	//One way
	const char* PlayerName = "Player1";

	//Another way
	char* Name = (char*)"Luke";
	std::cout << Name << std::endl;

	/*
	We don't actually need to make the char array
	const. However, because it is an array, we cannot
	change the size.

	Char pointers are not actually heap allocated, so
	no need to delete them.
	*/
	

	//Unless we explicitly allocate on the heap
	//but doing so also allows us to modify the 
	//values inside.

	/*
	You'll notice that we need a char array of size
	5 to store 4 chars. The reason for that, is 
	because strings require an additional entry at
	the end of the string. A special character is added
	at the end so that the compiler knows when the end
	of the string is reached. '\0' is the special character.
	*/
	char* myString = new char[6]{"Lukee"};
	*(myString + 2) = 'c';
	*(myString + 3) = 'k';

	std::cout << myString << std::endl;

	/*
	The Standard library contains a string struct.
	We can define one like so:
	*/

	std::string city = "Toronto";
	city += ", Ontario";
	std::cout << city << std::endl;

	/*
	The standard library implementation of things is
	of course slow as ever:
	*/

	Timer timer;
	timer.start();

	for (int i = 0; i < 10000000; i++)
	{
		city[0] = 'A';
		city[1] = 'B';
		city[2] = 'C';
		city[3] = 'D';
		city[4] = 'E';
	}
	timer.stop();
	std::cout << "Execution time of std::string: " << timer.elapsedMilliseconds() << std::endl;

	timer.start();

	for (int i = 0; i < 10000000; i++)
	{
		*(myString) = 'A';
		*(myString + 1) = 'B';
		*(myString + 2) = 'C';
		*(myString + 3) = 'D';
		*(myString + 4) = 'E';
	}
	timer.stop();
	std::cout << "Execution time of char* : " << timer.elapsedMilliseconds() << std::endl;

	delete[] myString;

	std::cin.get();
}