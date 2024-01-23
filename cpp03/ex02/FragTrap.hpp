#ifndef CPP_FRAGTRAP_HPP
#define CPP_FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &rhs);
	~FragTrap();
	FragTrap &operator=(const FragTrap &rhs);

	void highFivesGuys();
	void attack(const std::string &target);

private:
	static const unsigned int kInitHitPoints_ = 100;
	static const unsigned int kInitEnergyPoints_ = 100;
	static const unsigned int kInitAttackDamage_ = 30;
};

#endif
