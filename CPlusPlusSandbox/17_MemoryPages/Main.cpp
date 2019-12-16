#include <iostream>

#include <stdio.h>
#include <windows.h>

int main()
{
	/*
	======================PAGE TABLE=======================
	A Page Table is created when your application starts.
	A Page Table is a data structure with a hashmap like functionality
	that organizes the available memory for your application.

	A Page Table is created by your operating system. 

	When your application starts on your computer, the OS 
	gives your application a set amount of memory to use.
	However, many different applications (or processes) may
	be executing at the same time using lots of memory. As 
	a result, the available memory in the RAM may be fragmented
	and not nicely packed. 

	The purpose of the Page Table is to take the available physical
	memory given to the application and rearrange the memory in a 
	virtual table such that it is a continugous block of memory.


	Page Table (Virtual Memory)				Physical Address Space (RAM)

	---|------------						---|---------------
	   | - - - - - -						   |- - - - - - - -
	A  | - - - - - -						G  |- - - - - - - -
	   | - - - - - -						   |- - - - - - - -
	---|------------						---|---------------
	   | - - - - - -						   |- - - - - - - -
	B  | - - - - - -						Z  |- - - - - - - -
	   | - - - - - -						   |- - - - - - - -
	---|------------						---|---------------
	   | - - - - - -						   |- - - - - - - -
	C  | - - - - - -						A  |- - - - - - - -
	   | - - - - - -						   |- - - - - - - -
	---|------------						---|---------------
	   | - - - - - -						   |- - - - - - - -
	D  | - - - - - -						C  |- - - - - - - -
	   | - - - - - -						   |- - - - - - - -
	---|------------						---|---------------
	   | - - - - - -						   |- - - - - - - -
	E  | - - - - - -						E  |- - - - - - - -
	   | - - - - - -						   |- - - - - - - -
	---|------------						---|---------------

	Each process only works with the Page Table's virtual memory directly
	and not the actual physical memory (RAM).

	Each time your application requests access to some memory, the OS must
	retrieve the actual physical memory using the Page Table. Unless, the same
	memory was recently retrieved and is cached.

	======================MEMORY PAGE=======================
	However, the Page Table does not map each individual memory address
	1 : 1 from virtual to physical memory. This would take an large amount
	of resources to retain the mapping. Instead, what the OS does is make
	chunks of data. These are called Memory Pages. A memory page is a 
	chunk of memory that will be used by one and only one process.

	The size of these Pages are not always the same. They are different for
	every system. You can check your page size with the code below : 
	*/

	SYSTEM_INFO si;
	GetSystemInfo(&si);
	printf("The page size for this system is %u bytes.\n", si.dwPageSize);

	/*
	So the Page Table looks a bit more like this (assuming a page contains 1024 words): 


	1. Application wants to access memory word 10

					Page Table
					==========================================================
					|		Virtual Memory			|		Mapping			 |
					==========================================================
					|		Page 1 Addresses		|		Page Frame		 |
					|			1 - 1024			|			7			 |
	10 --------->	|===============================|=========================
					|		Page 2 Addresses		|		Page Frame		 |
					|			1025 - 2048			|			2			 |
					|===============================|=========================
					|		Page 3 Addresses		|		Disk			 |
					|			2049 - 3072			|						 |
					|===============================|=========================
					|		Page 4 Addresses		|		Page Frame		 |
					|			3073 - 4096			|			10			 |
					==========================================================

		In the case of memory address 10, it can be found in Virtual Memory at page 1.
		The Page Table has mapped page 1 to be found at Page frame 7 (RAM).

		The OS will then find the appropriate memory page in physical memory and return
		the requested word. In this case, it is just an offset of 10.

		If however, we had requested a word from Page 3 in virtual memory. The page is
		currently on the Disk. What happens is a page in physical memory is unloaded
		and the requested disk is then loaded into memory where the old page once was.

		This is a slow process. But when the changes are made, the Page Table is updated
		and the value returned the process.

	============================MEMORY WORD================================
	WORDs are the size of the registers found on your CPU. A WORD is the size
	of data that can be loaded with one CPU cycle. 

	32 bit cpu		|		4 byte WORD
	64 bit cpu		|		8 byte WORD


	All of this is just to say, watch your memory. The smaller your memory footprint is
	the faster you can load that memory and the more you can keep in your caches. 

	If you are working with a 64 bit system. Then you should, as much as possible, aim
	for your objects to be 8 bytes or less (this obviously may not be possible all the time).

	Having the ability to smarly organize your memory such that you won't have any
	cache misses will greatly increase your speed. In some cases 1000x or more.
	*/
	std::cin.get();
}