#include "Zombie.hpp"

int main()
{
	Zombie *zombie;
	zombie = newZombie("Foo on Heap");
	zombie->announce();
	delete zombie;
	randomChump("Foo on Stack");
//	delete zombie;
}
