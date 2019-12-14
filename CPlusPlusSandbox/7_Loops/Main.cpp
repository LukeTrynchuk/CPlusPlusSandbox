#include <iostream>

void Log(const char* message)
{
	std::cout << message << std::endl;
}

int main()
{
	//==========FOR LOOPS==============


	//Print "Hello World!" 5 times.
	Log("Hello World!");
	Log("Hello World!");
	Log("Hello World!");
	Log("Hello World!");
	Log("Hello World!");

	//Alternatively, we can use a loop. 
	//A loop will execute a series of statements
	//n number of times.


	/*
		First, much like an if statement,
		create the structure of the loop: 

		for()
		{

		}

		Then we need a counter. Something that
		will count the number of loops. In most
		cases, the default is "i". Though not
		descriptive, it is a very common name
		for a loop counter. 

		for(int i = 0;)
		{

		}

		This means that i will be initialized at
		0. However, we could have chosen any value.

		Next, write the conditional. The conditional
		will be what stops the loop. While the condition
		is true, the loop will continue to execute.

		In this case, we want to loop 5 times.

		for(int i = 0; i < 5;)
		{

		}

		Next we need to increment our counter every loop.

		for(int i = 0; i < 5; i++)
		{

		}

		i++ is equivalent to i = i + 1
		
		The value of i over the course of the
		loop will be as follows : 

		0,1,2,3,4,5

		Of course, when the value of 5 is reached the loop will stop.
	*/
	for (int i = 0; i < 5; i++)
	{
		Log("Hello World!");
	}



	//===========WHILE LOOPS============
	/*
		A while loop is very similar to the for
		loop, except it only contains the conditional.

		You could write the same logic in a while loop like so :
	*/

	int i = 0;
	while (i < 5)
	{
		i++;
		Log("Hello World!");
	}

	//Be sure to remember to add the "i++" otherwise
	//you'll end up with an endless loop.

	/*
		The while loop have the conditional at top.
		This means the condition will execute before
		everything else. In this case, the loop will
		execute 5 times.

		You can also write it with the condition at the
		bottom which will execute after all the statements.
	
	*/

	i = 10;

	{
		i++;
		Log("Hello World!");
	}while(i < 5);

	/*
		Even though 10 is clearly larger than 5 and would fail
		the while loop condition, because the condition occures 
		after all the statements execute. In this case, the loop
		will execute 1 time only.
	*/

	std::cin.get();
}