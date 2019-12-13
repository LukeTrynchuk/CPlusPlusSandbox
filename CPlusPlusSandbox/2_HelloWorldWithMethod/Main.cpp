#include <iostream>

/*
	The line below is a declaration.
	When the compiler sees a declaration,
	it beleives that somewhere in the project
	there is a method that contains the 
	specified syntax that it can use.

	The compiler will not return any errors
	for a missing method when a declaration is
	provided. If the function is not actually
	found in the project then the linker will
	return an error because it can not find 
	the proper function. 

	The compiler will compile individual files 
	and the linker will link the produced .obj
	files.

	================COMPILER================
	The compiler's job is to convert the raw 
	text files that we write (.cpp, .h, etc..)
	into an executable binary that the computer
	can understand. When the compiler is finished
	with compiling, the compiler will produce 
	.obj files. A number of things occure 
	when the compiler compiles.

	1. Preprocessor directives
		The compiler will evaluate all preprocessor
		directives found in the code. These are
		statements that are preceded with the
		hash (#) symbol.

	2. Create abstract syntax tree
		The compiler will then take all the code
		we've written and create a structure to 
		contain all the data in. The tree does
		not represent every syntactical detail
		about our code but rather processes the
		code such that is can be reasoned with 
		and converted into a more computer friendly
		format.

		Syntactical details that are recorded are
		things such as parenthesis, if statements,
		and blocks of code. In the case of C++ where
		the language is not white space dependant, things
		such as white space are not represented in the
		AST (abstract syntax tree).

	3. Generate Binary code
		The compiler will take the AST and generate
		binary code. Binary code is what the cpu will
		execute.

		Other data such as constant value variables
		are serialized into separate files.

	=================LINKER=======================
	The linker's job is to take all the files that
	the compiler has produced and bring them all
	together. Prior to the linker, any files that
	refer to code in separate files, have no concept
	or knowledge of that code. The linker brings it all
	together and fits it into one package.

	One job of the linker is to locate the main()
	function. Beyond linking files together, the linker
	must sift through the code and find the connections
	and relations between our code.
*/
void Log(const char*);

int main()
{
	Log("Hello World!");
	std::cin.get();
}