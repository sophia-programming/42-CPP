#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cerr << "(Animal Default constructor called)" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cerr << "(Animal " << type << " constructor called)" << std::endl;
}

Animal::Animal(const Animal &rhs)
{
	std::cerr << "(Animal copy constructor called)" << std::endl;
	*this = rhs;
}

Animal::~Animal()
{
	std::cerr << "(Animal destructor called)" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs) {
	if (this != &rhs) {
		type = rhs.getType();
	}
	return *this;
}

void Animal::makeSound() const
{
	std::cout << BOLD << "..." << STOP << std::endl;
}

const std::string &Animal::getType() const {
	return type;
}

void Animal::setType(const std::string &type) {
	this->type = type;
}
