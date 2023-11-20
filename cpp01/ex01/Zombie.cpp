#include "Zombie.hpp"

void Zombie::announce() {
	std::cout
	<< Green
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
	<< Red
	<< name_
	<< " is dead!!!!"
	<< Stop
	<< std::endl;
}
/* accessor */
void Zombie::setName(const std::string &name)
{
	name_ = name;
}
