#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cerr << "(WrongCat default constructor called)" << std::endl;
}

WrongCat::WrongCat(const WrongCat &rhs)
{
	std::cerr << "(WrongCat copy constructor called)" << std::endl;
	*this = rhs;
}

WrongCat::~WrongCat()
{
	std::cerr << "(WrongCat destructor called)" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
	if (this != &rhs) {
		WrongAnimal::type = rhs.WrongAnimal::getType();
	}
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << RED << "NO!" << STOP << std::endl;
}
