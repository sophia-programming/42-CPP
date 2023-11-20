#include "Zombie.hpp"

Zombie::Zombie(const std::string &name)
: name_(name) {}

void Zombie::announce() {
	std::cout
	<<
	name_
	<< ":  "
	<< " BraiiiiiiinnnzzzZ..."
	<< std::endl;
}

Zombie::Zombie()
:name_("Zombie") {}

Zombie::~Zombie()
{
	std::cout << Underline << "Zombie() destructor is called" << Stop << std::endl;
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
