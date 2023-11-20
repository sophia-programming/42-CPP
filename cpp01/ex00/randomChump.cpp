#include "Zombie.hpp"

/* Chump is word(slang) similar to 'insane' ,'stupid', or 'foolish'*/
void randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}
