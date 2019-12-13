/*
	When a hash(#) is used, we are using a preprocessor
	statement. Preprocessor statements get evaluated
	before the compiler compiles the code. 

	In this case, this preprocessor statement includes 
	code from iostream.
*/
#include <iostream>

int main()
{
	//cout is the method, std is the namespace.

	std::cout << "Hello World!" << std::endl;

	/*
		alternatively, we also could have written
		std::cout.print("Hello World!").print(std::endl);
	*/

	//std::cin.get(); waits for input from the console window.
	std::cin.get();

	/*
		if we do not return anything in main()
		it is assumed that we are returning 0 as an integer.
	
		main() is the only case where this occures. All other
		methods returning an integer do not assume a default return
		value. 
	
		A return value of 0 represents a succesful execution. 
		Any other return value will represent a different outcome.
	
		Here are some other common return codes : 
	
		10			:			non-existant locations in request
		11			:			requested dates in the past
		12			:			inverted date range in request
		20			:			no flights found
		30			:			protocol violation
		31			:			connection error
		32			:			resource error
		33			:			timeout

		as referenced at https://akrzemi1.wordpress.com/2017/09/04/using-error-codes-effectively/
	*/
} 