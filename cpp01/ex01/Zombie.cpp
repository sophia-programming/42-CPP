//
// Created by 小平波琉 on 2022/08/04.
//
#include "Zombie.hpp"

void Zombie::announce() {
	std::cout
	<< GreenColor
	<<
	name_
	<< ":  "
	<< " BraiiiiiiinnnzzzZ..."
	<< std::endl;
}

Zombie::Zombie() : name_("zombie") {}

Zombie::Zombie(const std::string &name) : name_(name) {}

Zombie::~Zombie()
{
	std::cout
	<< RedColor
	<< name_
	<< " is dead!!!!"
	<< StopColor
	<< std::endl;
}
/* accessor */
void Zombie::setName(const std::string &name)
{
	name_ = name;
}
