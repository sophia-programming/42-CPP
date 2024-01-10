#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) :
name_(name), weapon_(weapon) {}

HumanA::~HumanA() {}

/* accessor */
const std::string &HumanA::getName() const
{
	return name_;
}

void HumanA::setName(const std::string &name)
{
	name_ = name;
}

Weapon &HumanA::getWeapon() const
{
	return weapon_;
}

void HumanA::setWeapon(Weapon &weapon)
{
	weapon_ = weapon;
}
