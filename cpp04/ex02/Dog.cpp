#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	std::cerr << "(Dog default constructor called)" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog &rhs) : AAnimal(rhs)
{
	std::cerr << "(Dog copy constructor called)" << std::endl;
	if (rhs.brain) {
		brain = new Brain(*rhs.brain);
	} else {
		brain = NULL;
	}
}

Dog::~Dog()
{
	std::cerr << "(Dog destructor called)" << std::endl;
	delete brain;
}

Dog &Dog::operator=(const Dog &rhs) {
	if (this != &rhs) {
		AAnimal::operator=(rhs);
		delete brain;
		if (rhs.brain) {
			brain = new Brain(*rhs.brain);
		} else {
			brain = NULL;
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
