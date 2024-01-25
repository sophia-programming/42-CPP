#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "(ScavTrap default constructor called)" << std::endl;
	name_ = "scav";
	hitPoints_ = kInitHitPoints_;
	energyPoints_ = kInitEnergyPoints_;
	attackDamage_ = kInitAttackDamage_;
}

ScavTrap::ScavTrap(const std::string &name)
{
	std::cout << "(ScavTrap " << name << " constructor called)" << std::endl;
	name_ = name;
	hitPoints_ = kInitHitPoints_;
	energyPoints_ = kInitEnergyPoints_;
	attackDamage_ = kInitAttackDamage_;
}

ScavTrap::ScavTrap(const ScavTrap &rhs)
{
	std::cout << "(ScavTrap copy constructor called)" << std::endl;
	*this = rhs;
}

ScavTrap::~ScavTrap()
{
	std::cout << "(ScavTrap " << name_ << " destructor called)" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
	if (this != &rhs) {
		name_ = rhs.getName();
		hitPoints_ = rhs.getHitPoints();
		energyPoints_ = rhs.getEnergyPoint();
		attackDamage_ = rhs.getAttackDamage();
	}
	return *this;
}

void ScavTrap::attack(std::string const &target)
{
	if (energyPoints_ > 0) {
		std::cout << "ScavTrap " << name_ << " attacks " << target
				  << ", causing " << attackDamage_ << " points of damage!" << std::endl;
		energyPoints_--;
	} else {
		std::cout << "ScavTrap " << name_ << " has no energy left to attack!" << std::endl;
	}
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
