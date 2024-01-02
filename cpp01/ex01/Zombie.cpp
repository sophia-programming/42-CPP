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

Zombie::Zombie(const std::string &name)
: name_(name) {}

Zombie::Zombie()
: name_("zombie") {}

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
const std::string &Zombie::getName() const
{
	return name_;
}

void Zombie::setName(const std::string &name)
{
	name_ = name;
}
