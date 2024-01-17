#include "Weapon.hpp"

Weapon::Weapon(std::string type) :type_(type) {}

Weapon::~Weapon() {}

void Weapon::setType(const std::string &type)
{
	type_ = type;
}

const std::string &Weapon::getType()
{
	return type_;
}
