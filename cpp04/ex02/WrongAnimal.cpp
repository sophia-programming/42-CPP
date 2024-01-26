#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cerr << "(WrongAnimal constructor called)" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cerr << "(WrongAnimal " << type << " constructor called)" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs)
{
	std::cerr << "(WrongAnimal copy constructor called)" << std::endl;
	type = rhs.getType();
}

WrongAnimal::~WrongAnimal()
{
	std::cerr << "(WrongAnimale destructor called)" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
	if (this != &rhs) {
		type = rhs.getType();
	}
	return *this;
}

const std::string &WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << RED << "OMG!" << STOP << std::endl;
}
