#include <iostream>

class Enemy
{
public:
	static bool dead;
	int attack = 5;
};

bool Enemy::dead;

int main()
{
	Enemy e1;
	Enemy e2;

	//Two non-static variables, addresses should be different
	std::cout << &e1.attack << std::endl;
	std::cout << &e2.attack << std::endl;


	//Two static variables, addressed should be same
	std::cout << &e1.dead << std::endl;
	std::cout << &e2.dead << std::endl;

	std::cin.get();
}