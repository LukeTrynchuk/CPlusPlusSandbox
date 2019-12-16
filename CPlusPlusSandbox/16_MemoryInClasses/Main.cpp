#include <iostream>

class EmptyClass
{

};

class EmptyClassWithMethod
{
public:
	void Func()
	{

	}

	void Func2()
	{

	}

	void Func3()
	{

	}

	void Func4(int var)
	{

	}
};

class Player
{
	int health;
};

class Enemy
{
	int health;
	int damage;
};

class Health
{
	bool dead;
};

class Health2
{
	bool dead;
	bool alive;
};

class Health3
{
	bool dead;
	bool alive;
	bool hurt;
};

class ShortClass
{
	short id;
};

class ShortClass2
{
	short id;
	bool dead;
};

class A
{
	int x;
	int y;
};

class B
{
	int x;
	int y;
	static int z;
	static int z2;
	static int z3;
	static int z4;
};

class C
{
	bool b;
};

class D
{
	bool b;
	int i;
};

class E
{
	bool b1;
	bool b2;
	bool b3;
	bool b4;

	int i;
};

class F
{
	bool b;
	int i;
	double d;
};

class G
{
	bool b1;
	bool b2;
	bool b3;
	bool b4;
	bool b5;
	bool b6;
};

class H
{
	bool b;
	G _g;
};

class I
{
	double d;
	bool b;
};

class J
{
	double d;
};

class K
{
	bool b;
	J _j;
};

class L
{
	bool b1;
	int i1;
	bool b2;
	int i2;
	bool b3;
	int i3;
};

class M
{
	bool b1;
	bool b2;
	bool b3;
	int i1;
	int i2;
	int i3;
};

class N
{
	int x;
	int y;
};

class O : public N
{
	int z;
};

class P
{
	virtual void SomeFunction()
	{

	}
};

class Q : public P
{
	virtual void SomeNewFunction()
	{

	}
};

class R
{
	int myInt;
};

class S : public virtual R
{
};

class T : public virtual R
{
};

class U : public S, public T
{
};

int main()
{
	/*
	=====================MEMORY IN CLASSES===================
	Memory in classes works in slightly different ways as
	previously explained in 3_Variables.

	Below are some variables
	*/

	//int = 4 bytes
	int x = 10;
	std::cout << "Size of int: " << sizeof(x) << std::endl;

	//bool = 1 byte
	bool b = true;
	std::cout << "Size of bool: " << sizeof(b) << std::endl;

	//char = 1 bytes
	char c = 'A';
	std::cout << "Size of char: " << sizeof(c) << std::endl;

	/*
	Below we've created in instance of type EmptyClass, which
	contains nothing inside. However, you'll notice that it
	still takes up 1 byte of data.

	The reason an empty class is atleast 1 byte large is because,
	as explained in 3_Variables, the smallest amount of data that
	can be reasoned is 1 byte. That is why booleans use 1 byte of
	data as opposed to 1 bit.
	*/
	EmptyClass emptyClass;
	std::cout << std::endl << "Size of empty class: " << sizeof(emptyClass) << std::endl;

	/*
	Below is a class with several methods. When we get the size of
	the "emptyWithMethod" we still see that it is only 1 byte large.
	This is because similarly to the "emptyClass", it does not contain
	any data members. However, the smallest an object can be is 1 byte.

	Don't be fooled though. Each method inside the class takes up space
	in memory. 
	*/
	EmptyClassWithMethod emptyWithMethod;
	std::cout << std::endl << "Size of empty class with method: " << sizeof(EmptyClassWithMethod) << std::endl;

	/*
	A class that contains an int is 4 bytes large because an int is
	4 bytes large.
	*/
	Player p;
	std::cout << "Size of class with int: " << sizeof(p) << std::endl;

	/*
	A class that contains 2 ints is 8 bytes large, because an int is
	4 bytes and there are 2 ints. Therefor, 4 * 2 = 8 bytes.
	*/
	Enemy e;
	std::cout << "Size of class with 2 ints: " << sizeof(e) << std::endl;

	/*
	Health only contains a single boolean. A boolean is 1 byte in size.
	Therefor "h" is 1 byte large.
	*/
	Health h;
	std::cout << "Size of class with bool: " << sizeof(h) << std::endl;

	/*
	Health 2 contains 2 booleans and therefor is 2 bytes large.
	*/
	Health2 h2;
	std::cout << "Size of class with 2 bools: " << sizeof(h2) << std::endl;

	/*
	Health3 contains 3 booleans and is 3 bytes large.
	*/
	Health3 h3;
	std::cout << "Size of class with 3 bools: " << sizeof(h3) << std::endl;

	/*
	ShortClass contains 1 short and therefor is 2 bytes large
	*/
	ShortClass sc;
	std::cout << "Size of class with short: " << sizeof(sc) << std::endl;


	ShortClass2 sc2;
	std::cout << "Size of class with 1 short, and 1 boolean: " << sizeof(sc2) << std::endl;
	std::cout << "==========================================================" << std::endl << std::endl;

	/*
	Here's where it get interesting. ShortClass2 contains 1 short (2 bytes)
	and 1 bool (1 byte). It should be 3 bytes large but is actually 4 bytes.

	Why?

	==========================SIZE OF OBJECTS==============================
	There are multiple factors to the total size of an object in C++. 

	1.Size of all non-static data members
	2.Byte alignment or byte padding
	3.Order of data members
	4.Size of its immediate base class
	5.The existence of virtual function(s) (Dynamic polymorphism using virtual functions).
	6.Compiler being used
	7.Mode of inheritance
	*/

	/*
	1. Size of all non-static data members
		As previously shown in 15_StaticInsideClass, static data members do not
		contribute to the size of an individual entity.

		Class A contains 2 data members. 
		Class B contains 2 data members and 4 other static data members.

		The size of both objects should be exactly the same.
	*/
	A _a;
	B _b;

	std::cout << "___________Non Static Data members____________" << std::endl;
	std::cout << "Size of A (2 data members): " << sizeof(_a) << std::endl;
	std::cout << "Size of B (2 data members and 4 static members): " << sizeof(_b) << std::endl << std::endl;

	/*
	2. Byte alignment or byte padding
		When memory is allocated for a particular object, something occurs
		called Byte Alignment or Byte Padding. I will refer to this as 
		byte padding from this point forward.

		Byte padding is used to align our data in as effecient manner as possible.
		Byte padding inserts one or more empty bytes of data between memory
		adresses of different sizes. Being able to skip exact sizes in data is 
		more important than the empty memory inbetween for the compiler. 

		Let's take an example class 

		class C
		{
			bool b;
		};

		If each byte is represented with a pair of asterisk (**), then the 
		memory makeup of class "C" can be represented as such : 

		bool b
		 **

		The largest increment of data the cpu will need to make to read a 
		data member is 1 byte. Therefor everything stored in C will be in
		increments of 1 byte.

		Now, let's take a look at class D:

		class D 
		{
			bool b;
			int i;
		};

		The largest increment of data the cpu will need to jump is 4 bytes,
		because an int is 4 bytes large. Therefor the total size in bytes is
		8 and the memory makeup can be represented as such: 

		bool b		| int i
		** -- -- --   ** ** ** **

		Notice how 3 bytes are unused inbetween "b" and "i".

		What about class E? 

		class E
		{
			bool b1;
			bool b2;
			bool b3;
			bool b4;

			int i;
		};

		The largest data member is the int which is 4 bytes. So data will
		increment in 4 byte sized chunks. The memory will be layed out as such:

		b1 b2 b3 b4      i
		** ** ** **  ** ** ** **

		Even though class E has 3 additional booleans than D, E is the exact same
		size in memory. Facinating!

		Class F contains a double (8 bytes) and a boolean (1 byte). The increment
		will be in 8 bytes and therefor the total size should be 16 bytes.

		Class G contains 6 booleans. The total size of G is 6 bytes large. H contains
		G and a boolean. You may believe that the largest memory increment is 6 bytes:

		bool b			  |			G		  | 12 total bytes
		** -- -- -- -- -- | ** ** ** ** ** ** |

		However, the compiler will actually take the data out of G and compress it such
		that the largest memory increment is 1 byte:

		b  |g.b1|g.b2|g.b3|g.b4|g.b5|g.b6| 7 total bytes 
		** | ** | ** | ** | ** | ** | ** |

		And, as shown in class K, other objects inside of a class can determine the max
		memory increment for a parent class.

		More on memory and memory segments in next project.
	*/

	C _c;
	D _d;
	E _e;
	F _f;
	G _g;
	H _h;
	I _i;
	K _k;

	std::cout << "_________________Byte Padding_________________" << std::endl;
	std::cout << "Size of class with bool: " << sizeof(_c) << std::endl;
	std::cout << "Size of class with bool and int: " << sizeof(_d) << std::endl;
	std::cout << "Size of class with 3 bool and 1 int: " << sizeof(_e) << std::endl;
	std::cout << "Size of class with bool and double: " << sizeof(_e) << std::endl;

	std::cout << "Size of class with 6 booleans: " << sizeof(_g) << std::endl;
	std::cout << "Size of class with a collection of 6 booleans and 1 boolean: " << sizeof(_h) << std::endl;
	std::cout << "Size of class with double and bool: " << sizeof(_i) << std::endl;
	std::cout << "Size of class with bool and double container: " << sizeof(_k) << std::endl << std::endl;

	/*
	3.Order of data members
		Building off of the previous point, organizing our data within a class
		greatly affects how large a class can be.

		By packing our smaller sized data types together, we can optimize how 
		our data is stored. The worst thing to do while organizing our data
		is two sandwhich small data inbetween larger data.

		Class L and Class M contains the exact same variables but in just a 
		different order. Instances of M are 8 bytes smaller than instances
		of L. 
	*/

	L _l;
	M _m;

	std::cout << "______________Data Member Ordering_____________" << std::endl;
	std::cout << "Size of poorly organized class data: " << sizeof(_l) << std::endl;
	std::cout << "Size of optimally organized class data: " << sizeof(_m) << std::endl << std::endl;

	/*
	4.Size of base class
		If a class has a base class that it inherits from, the size of the base
		class will be added to the super class.
	*/

	N _n;
	O _o;

	std::cout << "________________Base Class Size________________" << std::endl;
	std::cout << "Size of base class: " << sizeof(_n) << std::endl;
	std::cout << "Size of super class with only one int: " << sizeof(_o) << std::endl << std::endl;

	/*
	5.The existence of virtual function(s) (Dynamic polymorphism using virtual functions).
		Unlike regular functions in a class, which don't add to the size of an instance,
		Virtual functions do. When a class has a virtual function, a 4 byte pointer is added
		to the class which pointer to a virtual table. The virtual table resolves virtual 
		functions. Any new virtual functions added to a class will not increase the 
		instance size after the first virtual function.
	*/

	P _p;
	Q _q;

	std::cout << "_______________Virtual Functions_______________" << std::endl;
	std::cout << "Size of base class with virtual function: " << sizeof(_p) << std::endl;
	std::cout << "Size of super class with additional virtual function: " << sizeof(_q) << std::endl << std::endl;

	/*
	6.Compiler being used
		Compilers are different and some handle memory slightly different than others.
		Be sure to do tests with your specific compiler. Variations may vary.
	*/

	/*
	7.Mode of inheritance
		When a class is virtually inherited, the derived class will add the size of the
		base class + an additional 4 bytes of data for a virtual base class pointer.

		However, just like with virtual functions, only a single virtual pointer will be
		stored. This means that there will only every be a 4 byte addition to the size 
		from virtual inheritance.
	*/

	R _r;
	S _s;
	T _t;
	U _u;

	std::cout << "______________Mode of inheritance______________" << std::endl;
	std::cout << "Size of base class with int: " << sizeof(_r) << std::endl;
	std::cout << "Size of first virtual derived class: " << sizeof(_s) << std::endl;
	std::cout << "Size of second virtual derived class: " << sizeof(_t) << std::endl;
	std::cout << "Size of derived class of both previous classes: " << sizeof(_u) << std::endl;

	std::cin.get();
}