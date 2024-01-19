#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
name_("clap"),
hitPoint_(kInitHitPoint_),
energyPoint_(kInitEnergyPoint_),
attackDamage_(kInitAttackDamage_)
{
	std::cerr << "(ClapTrap default constructor called)" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) :
name_(name),
hitPoint_(kInitHitPoint_),
energyPoint_(kInitEnergyPoint_),
attackDamage_(kInitAttackDamage_)
{
	std::cerr << "(ClapTrap constructor called)" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cerr << "(ClapTrap destructor called)" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs)
{
	std::cerr << "(ClapTrap copy constructor called)" << std::endl;
	*this = rhs;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
	if (this != &rhs) {
		name_ = rhs.getName();
		hitPoint_ = rhs.getHitPoints();
		energyPoint_ = rhs.getEnergyPoint();
		attackDamage_ = rhs.getAttackDamage();
	}
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	std::cout
	<< RED
	<< "ClapTrap "
	<< name_
	<< " attacks "
	<< target
	<< ", causing "
	<< attackDamage_
	<< " points of damage!"
	<< STOP
	<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoint_ <= amount) {
		hitPoint_ = 0;
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
		hitPoint_ = hitPoint_ - amount;
		std::cout
		<< CYAN
		<< "ClapTrap "
		<< name_
		<< " taken "
		<< amount
		<< " points of damage. ("
		<< hitPoint_
		<< "HP left)"
		<< STOP
		<< std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	hitPoint_ += amount;
	std::cout
	<< GREEN
	<< "ClapTrap "
	<< name_
	<< " is repaired "
	<< amount
	<< " points. ("
	<< hitPoint_
	<< "HP left)"
	<< STOP
	<< std::endl;
}

const std::string &ClapTrap::getName() const {
	return name_;
}

unsigned int ClapTrap::getHitPoints() const {
	return hitPoint_;
}

unsigned int ClapTrap::getEnergyPoint() const {
	return energyPoint_;
}

unsigned int ClapTrap::getAttackDamage() const {
	return attackDamage_;
}
