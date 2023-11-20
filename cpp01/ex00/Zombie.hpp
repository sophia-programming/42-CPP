#ifndef CPP_ZOMBIE_HPP
#define CPP_ZOMBIE_HPP

#include "Color.hpp"
#include <string>
#include <iostream>

class Zombie {
public:
	Zombie(const std::string &name);
	Zombie();
	~Zombie();

	/* functions */
	void announce();

	/* accessor */
	const std::string &getName() const;
	void setName(const std::string &name);

private:
	std::string name_;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
