#ifndef CPP_ZOMBIE_HPP
#define CPP_ZOMBIE_HPP
#include <iostream>
#include <string>
#include "color.hpp"

class Zombie {
public:
	Zombie();
	Zombie(const std::string &name);
	~Zombie();

	void announce(); const

	/* accessor */
	std::string &getName() const;
	void setName(const std::string &name);

private:
	std::string name_;
};

Zombie *zombieHorde(int N, std::string name);

#endif
