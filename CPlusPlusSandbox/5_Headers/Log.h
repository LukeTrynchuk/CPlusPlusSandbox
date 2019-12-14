/*
	===========HEADERS==============
	Header files are helpful files that
	help share the definition of functions
	so that other scripts can use functions
	that are found in different scripts.

	previously, if for example, you wanted
	to use the Log() function in main.cpp,
	you would have to add :

	void Log(const char* message);

	in the file. However, this can become
	very tedious to add to EVERY file that
	may like to use that function. Additionally,
	what if we add new useful functions in the
	same file as Log()? The way we avoid this is
	by using header files. 

	By including : 

	#include "Log.h"

	in a file, we gain access to Log() as well
	as any other functions found in that file.
*/


/*
	#pragma once is a preprocessor directive
	(for more information on preprocessor directives
	see 2_HelloWorldWithMethod project).
	When added to a header file, this ensures 
	that this header file is only every added
	to a translation unit once. Meaning, that
	if we were to accidenly add this header
	file to a .cpp file more than once, this
	would ensure that the compiler only adds
	the code to that file once.
*/
#pragma once
#include <iostream>

void Log(const char* message);
void InitLog();