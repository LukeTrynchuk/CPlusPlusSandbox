#include "Log.h"

/*
	#include "Log.h" is used to include
	the log header file. This allows us to
	avoid having to declare the method we
	wish to use.

	Unlike #include <iostream>, we use
	quotation marks ("") instead of 
	angular brackets. Here's what they mean : 

	<>
		Angular brackets are used to include
		file that can be found in our include
		directory (project settings). These 
		are files that are sitting somewhere
		on our computer that are not local to 
		the current project. iostream in this
		case is not local and therefor we use 
		angular brackets.

	""
		Quotation marks are used for files that
		are found local to the current project.
		In this case "Log.h" is local to the current
		project and therefor we use quotation marks.
*/

int main()
{
	InitLog();
	Log("Hello World!");
	std::cin.get();
}