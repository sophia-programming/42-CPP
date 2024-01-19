#ifndef CPP_SCAVTRAP_HPP
#define CPP_SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{
public:
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &rhs);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &rhs);

	void attack(const std::string &target);
	void guardGate();

private:
	static const unsigned int kInitHitPoint_ = 100;
	static const unsigned int kInitEnergyPoint_ = 50;
	static const unsigned int kInitAttackDamage_ = 20;
};

#endif
