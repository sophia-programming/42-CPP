#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cerr << "(Cat default constructor called)" << std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat &rhs) : Animal(rhs)
{
	std::cerr << "(Cat copy constructor called)" << std::endl;
	if (rhs.brain) {
		brain = new Brain(*rhs.brain);
	} else {
		brain = NULL;
	}
}

Cat::~Cat()
{
	std::cerr << "(Cat destructor called)" << std::endl;
	delete brain;
}

Cat &Cat::operator=(const Cat &rhs) {
	if (this != &rhs) {
		Animal::operator=(rhs);
		delete brain;
		if (rhs.brain) {
			brain = new Brain(*rhs.brain);
		} else {
			brain = NULL;
		}
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << BLUE << "MEOW!" << STOP << std::endl;
}

Brain const *Cat::getBrain() const
{
	return brain;
}
