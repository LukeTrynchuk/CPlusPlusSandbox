#include "Log.h"
/*
	Conditionals are a way of checking
	if a statement evaulates to true (1).

	We can then include code in the case 
	that it is true. 
*/


int main()
{
	//Something to compare.
	int age = 5;
	
	//if our age int is less than 5, then we execute the code found
	//in between our braces {}
	if (age < 5)
	{
		Log("You are a child!");
	}

	//You can also write if statements this way.
	//this only works if the resulting code is only
	//one statement.
	if (age < 13) Log("You are a kid");

	//First we check if the age is greater than 19
	if (age > 19)
	{
		//if so, execute this code.
		Log("Here, have a beer");
	}
	//else (if the above condition resulted in false)
	else
	{
		//execute this code
		Log("No beer for you");
	}

	/*
		else statements are a way to execute some code
		if the above if statement resulted in false.

		Alternatively, the above code could have also been 
		written

		if(age > 19)
		{
			...
		}

		if(age < 19)
		{
			...
		}
	
	*/

	/*
		The below code adds if statments
		within the else statement. 
	*/
	if (age > 19)
	{
		Log("Here have a beer");
	}
	else
	{
		if (age > 12)
		{
			Log("Here have a pop");
		}
		else
		{
			Log("Here have a juice");
		}
	}

	/*
		However, this can be reduced in size
		as demonstrated below. The two are 
		completely equivalent, though the below
		style is used much more than the above.
	*/

	if (age > 19)
	{
		Log("Here have a beer");
	}
	else if (age > 12)
	{
		Log("Here have a pop");
	}
	else
	{
		Log("Here have a juice");
	}

	std::cin.get();
}