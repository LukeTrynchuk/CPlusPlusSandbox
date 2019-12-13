#include <iostream>

inline int Multiply(int a, int b)
{
	return a * b;
}

void MultiplyAndLog(int a, int b)
{
	int result = Multiply(a, b);
	std::cout << result << std::endl;
}

int main()
{
	MultiplyAndLog(3, 2);
	MultiplyAndLog(8, 4);
	MultiplyAndLog(30, 6);
	
	std::cin.get();
	return 0;
}
