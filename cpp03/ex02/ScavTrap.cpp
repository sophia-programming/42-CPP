#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cerr << "(ScavTrap default constructor called)" << std::endl;
	name_ = "scav";
	hitPoint_ = kInitHitPoint_;
	energyPoint_ = kInitEnergyPoint_;
	attackDamage_ = kInitAttackDamage_;
}

ScavTrap::ScavTrap(const std::string &name)
{
	std::cerr << "(ScavTrap " << name << " constructor called)" << std::endl;
	name_ = name;
	hitPoint_ = kInitHitPoint_;
	energyPoint_ = kInitEnergyPoint_;
	attackDamage_ = kInitAttackDamage_;
}

ScavTrap::ScavTrap(const ScavTrap &rhs)
{
	std::cerr << "(ScavTrap copy constructor called)" << std::endl;
	*this = rhs;
}

ScavTrap::~ScavTrap()
{
	std::cerr << "(ScavTrap " << name_ << " destructor called)" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
	if (this != &rhs) {
		name_ = rhs.getName();
		hitPoint_ = rhs.getHitPoints();
		energyPoint_ = rhs.getEnergyPoint();
		attackDamage_ = rhs.getAttackDamage();
	}
	return *this;
}

void ScavTrap::attack(std::string const &target)
{
	std::cout
	<< RED
	<< "ScavTrap "
	<< name_
	<< " attacks "
	<< target
	<< ", causing "
	<< attackDamage_
	<< " points of damage!"
	<< STOP
	<< std::endl;
}

void ScavTrap::guardGate()
{
	std::cout
	<< BOLD
	<< "ScavTrap "
	<< name_
	<< " is now in Gate keeper mode"
	<< STOP
	<< std::endl;
}
