//
// Created by 小平波琉 on 2022/08/04.
//

#include "Weapon.hpp"

Weapon::Weapon(std::string type) :type_(type) {}

Weapon::~Weapon() {}

void Weapon::setType(std::string type) {
	type_ = type;
}

const std::string &Weapon::getType()
{
	return type_;
}
