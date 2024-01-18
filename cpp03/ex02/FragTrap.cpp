//
// Created by 小平波琉 on 2022/08/04.
//

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cerr << "(FragTrap default constructor called)" << std::endl;
	name_ = "frag";
	hitPoint_ = kInitHitPoint_;
	energyPoint_ = kInitEnergyPoint_;
	attackDamage_ = kInitAttackDamage_;
}

FragTrap::FragTrap(const std::string &name)
{
	std::cerr << "(FragTrap " << name << " constructor called)" << std::endl;
	name_ = name;
	hitPoint_ = kInitHitPoint_;
	energyPoint_ = kInitEnergyPoint_;
	attackDamage_ = kInitAttackDamage_;
}

FragTrap::FragTrap(const FragTrap &rhs)
{
	std::cerr << "(FragTrap copy constructor called)" << std::endl;
	*this = rhs;
}

FragTrap::~FragTrap()
{
	std::cerr << "(FragTrap " << name_ << " destructor called)" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
	if (this != &rhs) {
		name_ = rhs.getName();
		hitPoint_ = rhs.getHitPoints();
		energyPoint_ = rhs.getEnergyPoint();
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
	std::cout
	<< RED
	<< "FragTrap "
	<< name_
	<< " attack "
	<< target
	<< ", causing "
	<< attackDamage_
	<< " points of damage!"
	<< STOP
	<< std::endl;
}
