#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cerr << "(AAnimal Default constructor called)" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type)
{
	std::cerr << "(AAnimal " << type << " constructor called)" << std::endl;
}

AAnimal::AAnimal(const AAnimal &rhs)
{
	std::cerr << "(AAnimal copy constructor called)" << std::endl;
	*this = rhs;
}

AAnimal::~AAnimal()
{
	std::cerr << "(AAnimal destructor called)" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs) {
	if (this != &rhs) {
		type = rhs.getType();
	}
	return *this;
}

void AAnimal::makeSound() const
{
	std::cout << BOLD << "..." << STOP << std::endl;
}

const std::string &AAnimal::getType() const {
	return type;
}

void AAnimal::setType(const std::string &type) {
	this->type = type;
}
