#include <iostream>
#include <array>
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
	=======================ARRAYS====================
	Arrays are a collection of data which contains only
	one type of data. In the below example our array contains
	a collection of ints. When we create an array, we must also
	declare the size of the array. Once we create an array, we 
	cannot resize it. In the below case, the size of the array is
	5. 

	Arrays start at index 0. The available indices for the
	array below are : 

	0,1,2,3,4

	When we create an array, the data inside is uninitialized.

	Below is are a couple examples of how you may initialize an
	array.
	*/

	//Manually
	int example[5];
	example[0] = 2;
	example[1] = 2;
	example[2] = 2;
	example[3] = 2;
	example[4] = 2;

	//Using a loop
	for (int i = 0; i < 5; i++)
	{
		example[i] = i;
	}

	/*
	Arrays store their data in a contigous manner. This means that
	the data is all stored right next to eachother. The total size
	of example is 20 bytes. All 20 bytes will be next to eachother.

	Arrays are just build upon pointers. As demonstrated below.
	*/

	//Normally you cannot set a pointer to a value directly,
	//however, you can set one pointer equal to another.
	int* ptr = example;

	/*
	So what is happening in the background when we use an
	array?

	Well when we create the array, the array is allocated all the
	memory in a contigous chunk. And the array (or pointer) points
	to the memory address that the chunk is located in.

	Array of ints with 5 indices:

	|   i = 0	  |		i = 1	|	 i = 2	  |   i = 3		|	 i = 4	  |
	| ** ** ** ** | ** ** ** ** | ** ** ** ** | ** ** ** ** | ** ** ** ** |

	^
	|
	------------ Array pointer points here.

	We can demonstrate what happens when we index into our array through
	the use of another pointer pointing to our array.

	The pointer "ptr" is pointing to the memory address starting with the
	first index of the array. If we dereferrence the ptr at that current
	address, the first 4 bytes will be read.

	|	i = 0	  |
	| ** ** ** ** |

	The pointer will read 4 bytes because the pointer points to a int type.
	If the pointer was a char instead of a int, it would only read and 
	interpret the first byte. 
	*/

	std::cout << *ptr << std::endl;

	/*
	When we index into our array like so :

	example[2]

	or 

	example[4]

	It is equivalent to the pointer jumping a number of bytes and in memory
	and interpreting the value there.
	*/

	std::cout << *(ptr + 1) << std::endl;

	/*
	First the pointer increments by a certain amount. In the above case, we
	add the value of 1 to the pointer and dereference the value found at 
	ptr + 1. 

	ptr + 1 is equivalent to example[1]. 

	The reason is because 1 represents the number of bytes to jump * the size of
	the data type. In the case of ptr, it is an int pointer. An int is 4 bytes,
	so the pointer will jump 4 * 1 bytes in memory (note that this does not
	set the pointer).

	  *---4 bytes---*
	  * <- here to  * <- here
	| ** ** ** ** | ** ** ** ** |
	
	We can jump to any index of the array using this method : 
	*/

	std::cout << *(ptr + 2) << std::endl;
	std::cout << *(ptr + 3) << std::endl;
	std::cout << *(ptr + 4) << std::endl;

	/*
	We can even do something crazy like this : 
	*/

	//This will read example[1]
	std::cout << *((int*)(((char*)ptr) + 4)) << std::endl;

	/*
	We can create arrays both on the stack and on the heap:
	*/

	//Stack
	int example2[5];
	for (int i = 0; i < 5; i++)
	{
		example2[i] = i;
	}

	//Heap
	int* example3 = new int[5];
	delete[] example3;

	/*
	One disadvantage to using built in C++ arrays, is that we
	can only check the size of an array that is created on the
	stack.
	*/

	int count = sizeof(example2) / sizeof(int);

	/*
	We can't use this trick to check the size of an array allocated
	on the heap, because sizeof(example3) would return the size of
	the pointer which is always 4 bytes.
	*/

	/*
	Another option we have is to use the standard library's array 
	data structure. Which is initialized like so:
	*/

	std::array<int, 5> myArray;

	//To check the size of the array we do
	int myArrayCount = myArray.size();

	for (int i = 0; i < myArrayCount; i++)
	{
		myArray[i] = i;
	}

	/*
	The disadvantage of using the std::array, is that the std::array
	is obviously more bulky than the built-in array. because of this,
	it is going to be slower. 
	*/

	Timer timer;
	timer.start();
	for (int i = 0; i < 100000000; i++)
	{
		myArray[0] = myArray[0] + 1;
		myArray[1] = myArray[1] + 1;
		myArray[2] = myArray[2] + 1;
		myArray[3] = myArray[3] + 1;
		myArray[4] = myArray[4] + 1;
	}
	timer.stop();

	std::cout << "Time to use std::array in milliseconds : " << timer.elapsedMilliseconds() << std::endl;
	
	timer.start();
	for (int i = 0; i < 100000000; i++)
	{
		example2[0] = example2[0] + 1;
		example2[1] = example2[1] + 1;
		example2[2] = example2[2] + 1;
		example2[3] = example2[3] + 1;
		example2[4] = example2[4] + 1;
	}
	timer.stop();

	std::cout << "Time to use built-in array in milliseconds : " << timer.elapsedMilliseconds() << std::endl;

	std::cin.get();
}