#include <iostream>

/*
==============STRUCTS VS CLASSES==============
Structs are very similar to classes. Here are 
some differences. 

1. Items are private by default in classes and
public by default in structs.

That's it.


Because of this, there are some differing opinions
on when to use a struct and when to use a class.

For the most part, it seems as though developers
have agreed that structs should be used for 
POD (Plain Old Data) which may or may not have
functions. Classes are then used for everything
else which may have complex inheritance trees and
many different functions, etc...
*/

struct Player
{
	int x, y;
	int speed;

	void Move();
};

void Player::Move()
{
	x += speed;
	y += speed;
}

int main()
{
	Player p;
	p.Move();
	
	std::cin.get();
}