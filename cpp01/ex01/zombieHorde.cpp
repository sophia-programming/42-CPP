//
// Created by 小平波琉 on 2022/08/04.
//

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *zombies = new Zombie[N];
	for (int i = 0; i < N; i++) {
		zombies[i].setName(name);
	}
	return zombies;
}

/*
 * horde :  a large unorganized group of individuals : a teeming crowd or throng hordes of peasants.
 */
