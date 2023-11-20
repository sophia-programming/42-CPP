#include "Zombie.hpp"
const int NbZombieHorde  = 100;

int main()
{
	Zombie *zombies = zombieHorde(NbZombieHorde, "Zombie");
	for (int i = 0; i < NbZombieHorde; i++) {
		std::cout << Green <<  "[" << i << "]" << Stop;
		zombies[i].announce();
	}
	delete [] zombies;
}
