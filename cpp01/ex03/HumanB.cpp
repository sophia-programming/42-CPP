#include "HumanB.hpp"

HumanB::HumanB(std::string name) :
name_(name), weapon_(NULL) {}

HumanB::~HumanB() {}

void HumanB::attack()
{
	std::cout << name_ << " attacks with their ";
	if (weapon_ == NULL)
		std::cout << "hand" << std::endl;
	else
		std::cout << weapon_->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	weapon_ = &weapon;
}
