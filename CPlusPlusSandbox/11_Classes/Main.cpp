#include <iostream>

/*
=================CLASSES=================
Classes go hand-in-hand with 
OOP (Object Oriented Programming). OOP
is a way to organize and structure our code
such that related data and functionality
can be grouped together.
*/

class Player
{
public:
	void Move();

private:
	int x, y;
	int speed;

protected:

};

void Player::Move()
{
	x = x + speed;
	y = y + speed;
}

int main()
{
	//Instance of type Player
	Player p;
	p.Move();

	std::cin.get();
}