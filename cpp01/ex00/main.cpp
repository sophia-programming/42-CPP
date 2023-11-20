#include "Zombie.hpp"

int main()
{
	Zombie *zombie;
	zombie = newZombie("Zombie on Heap");
	zombie->announce();
	delete zombie;
	randomChump("Zombie on Stack");
//	delete zombie;
}
