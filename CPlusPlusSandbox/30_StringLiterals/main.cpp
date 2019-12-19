#include <iostream>

int main()
{
	/*
	======================STRING LITERALS======================
	A string literal is a set of characters between two 
	double quotes (" ").
	*/

	"Luke"; //const char[]

	/*
	In the case of the above string literal, the string is of size
	5, even though there are only 4 chars. The reason, is that every
	string allocates one extra index at the end to signal the end of
	the string. The special character is '\0'. When the cpu reads that
	character, it assumes the end of the string. We can confirm this will
	the below example:
	*/

	//const means that we won't be changing the value
	const char* Name = "Play\0er1";
	std::cout << Name << std::endl;
	std::cout << strlen(Name) << std::endl; //Print length of string

	/*
	When the character \0 was found, the print function stopped printing out
	the value of Name.
	*/

	//You can declare strings like this as well
	char myString[] = u8"Value";
	wchar_t wideChar[] = L"Value";
	char16_t char16Bit[] = u"Value";
	char32_t char32Bit[] = U"Value";

	std::cout << "Size of char: " << sizeof(char) << std::endl;
	std::cout << "Size of wchar_t: " << sizeof(wchar_t) << std::endl;
	std::cout << "Size of char16_t: " << sizeof(char16_t) << std::endl;
	std::cout << "Size of char32_t: " << sizeof(char32_t) << std::endl;

	//Appending strings
	std::string name0 = std::string("Luke") + " Trynchuk";

	std::cin.get();
}