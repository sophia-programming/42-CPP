#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
name_("clap"),
hitPoints_(kInitHitPoints_),
energyPoints_(kInitEnergyPoints_),
attackDamage_(kInitAttackDamage_)
{
	std::cout << "(ClapTrap default constructor called)" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) :
name_(name),
hitPoints_(kInitHitPoints_),
energyPoints_(kInitEnergyPoints_),
attackDamage_(kInitAttackDamage_)
{
	std::cout << "(ClapTrap " << name << " constructor called)" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "(ClapTrap destructor called)" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs)
{
	std::cout << "(ClapTrap copy constructor called)" << std::endl;
	*this = rhs;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
	if (this != &rhs) {
		name_ = rhs.getName();
		hitPoints_ = rhs.getHitPoints();
		energyPoints_ = rhs.getEnergyPoints();
		attackDamage_ = rhs.getAttackDamage();
	}
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (energyPoints_ > 0) {
		std::cout << "ClapTrap " << name_ << " attacks " << target
				  << ", causing " << attackDamage_ << " points of damage!" << std::endl;
		energyPoints_--;
	} else {
		std::cout << "ClapTrap " << name_ << " has no energy left to attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints_ <= amount) {
		hitPoints_ = 0;
		std::cout
		<< RED
		<< "ClapTrap "
		<< name_
		<< " is dead!!"
		<< std::endl
		<< "[!!!!!!!!GAME OVER!!!!!!!!!]"
		<< STOP
		<< std::endl;
		exit(EXIT_FAILURE);
	} else {
		hitPoints_ = hitPoints_ - amount;
		std::cout
		<< CYAN
		<< "ClapTrap "
		<< name_
		<< " taken "
		<< amount
		<< " points of damage. ("
		<< hitPoints_
		<< "HP left)"
		<< STOP
		<< std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints_ > 0) {
		hitPoints_ += amount;
		std::cout << "ClapTrap " << name_ << " is repaired " << amount << " points." << std::endl;
		energyPoints_--;
	} else {
		std::cout << "ClapTrap " << name_ << " has no energy left to repair!" << std::endl;
	}
}

const std::string &ClapTrap::getName() const {
	return name_;
}

unsigned int ClapTrap::getHitPoints() const {
	return hitPoints_;
}

unsigned int ClapTrap::getEnergyPoints() const {
	return energyPoints_;
}

unsigned int ClapTrap::getAttackDamage() const {
	return attackDamage_;
}
