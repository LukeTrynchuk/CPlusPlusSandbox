#include <iostream>
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


class vec3
{
public:
	float x, y, z;

	vec3()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}
};

class A
{
public:
	vec3 pos1;
	vec3 pos2;
	vec3 pos3;
	vec3 pos4;
	vec3 pos5;
	vec3 pos6;
	vec3 pos7;
	vec3 pos8;
};

void Function1(A value)
{
	value.pos1.x = value.pos1.x + 1;
}

void Function2(A* value)
{
	(*value).pos1.x = (*value).pos1.x + 1;
}

int main()
{
	/*
	===========POINTER MEMORY AVOIDANCE===========
	An interesting use case for pointers is avoiding
	the overhead of passing large objects. 

	Let's take class "A", which is a large object.
	*/

	std::cout << "=================DATA SIZES==================" << std::endl;

	A _a;
	std::cout << "Size of class A: " << sizeof(_a) << " bytes" << std::endl;

	/*
	And a pointer is only ever 4 bytes : 
	*/

	A* ptr = &_a;
	std::cout << "Size of pointer: " << sizeof(ptr) << " bytes" << std::endl << std::endl;
	std::cout << "===================EXECUTION TIME=====================" << std::endl;
	/*
	Time to execute method by passing large class as parameter.
	*/
	Timer timer;
	
	timer.start();
	for (int i = 0; i < 100000000; i++)
	{
		Function1(_a);
	}
	timer.stop();

	std::cout << "Execution time using data directly: " << timer.elapsedMilliseconds() << "m" << std::endl;

	/*
	VS passing the pointer.
	*/

	timer.start();
	for (int i = 0; i < 100000000; i++)
	{
		Function2(ptr);
	}
	timer.stop();

	std::cout << "Execution time using pointer: " << timer.elapsedMilliseconds() << "m" << std::endl;

	std::cin.get();
}