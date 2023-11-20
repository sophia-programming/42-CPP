//
// Created by 小平波琉 on 2022/08/04.
//
#include "Zombie.hpp"
const int NbZombieHorde  = 100;

int main()
{
	Zombie *zombies = zombieHorde(NbZombieHorde, "Zombie");
	for (int i = 0; i < NbZombieHorde; i++) {
		std::cout << GreenColor <<  "[" << i << "]" << StopColor;
		zombies[i].announce();
	}
	delete [] zombies;
}
