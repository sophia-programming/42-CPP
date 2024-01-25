#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "(FragTrap default constructor called)" << std::endl;
	name_ = "frag";
	hitPoints_ = kInitHitPoints_;
	energyPoints_ = kInitEnergyPoints_;
	attackDamage_ = kInitAttackDamage_;
}

FragTrap::FragTrap(const std::string &name)
{
	std::cout << "(FragTrap " << name << " constructor called)" << std::endl;
	name_ = name;
	hitPoints_ = kInitHitPoints_;
	energyPoints_ = kInitEnergyPoints_;
	attackDamage_ = kInitAttackDamage_;
}

FragTrap::FragTrap(const FragTrap &rhs)
{
	std::cout << "(FragTrap copy constructor called)" << std::endl;
	*this = rhs;
}

FragTrap::~FragTrap()
{
	std::cout << "(FragTrap " << name_ << " destructor called)" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
	if (this != &rhs) {
		name_ = rhs.getName();
		hitPoints_ = rhs.getHitPoints();
		energyPoints_ = rhs.getEnergyPoint();
		attackDamage_ = rhs.getAttackDamage();
	}
	return *this;
}

void FragTrap::highFivesGuys()
{
	std::cout
	<< GREEN
	<< "That's great!! ScavTrap "
	<< name_
	<< "!" << std::endl
	<< "Yeah!! (high five)"
	<< STOP
	<< std::endl;
}
/*
 * [high five meaning]
 * a gesture of congratulation, solidarity, or greeting in which one person slaps the upraised palm of the hand against that of another.
 * (high five == (japanese)high touch)
 */

void FragTrap::attack(std::string const &target)
{
	if (energyPoints_ > 0) {
		std::cout << "FragTrap " << name_ << " attacks " << target
				  << ", causing " << attackDamage_ << " points of damage!" << std::endl;
		energyPoints_--;
	} else {
		std::cout << "FragTrap " << name_ << " has no energy left to attack!" << std::endl;
	}
}
