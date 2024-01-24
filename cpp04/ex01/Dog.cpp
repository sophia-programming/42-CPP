#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cerr << "(Dog default constructor called)" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog &rhs) : Animal(rhs)
{
	std::cerr << "(Dog copy constructor called)" << std::endl;
	if (rhs.brain) {
		brain = new Brain(*rhs.brain);
	} else {
		brain = nullptr;
	}
}

Dog::~Dog()
{
	std::cerr << "(Dog destructor called)" << std::endl;
	delete brain;
}

Dog &Dog::operator=(const Dog &rhs) {
	if (this != &rhs) {
		Animal::operator=(rhs);
		delete brain;
		if (rhs.brain) {
			brain = new Brain(*rhs.brain);
		} else {
			brain = nullptr;
		}
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << CYAN << "BOW BOW!" << STOP << std::endl;
}

Brain const *Dog::getBrain() const
{
	return brain;
}
