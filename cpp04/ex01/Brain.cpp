#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "(Brain default constructor called)" << std::endl;
}

Brain::Brain(const Brain &rhs)
{
	std::cout << "(Brain copy constructor called)" << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = rhs.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &rhs)
{
	std::cout << "(Brain assignment operator called)" << std::endl;
	if (this != &rhs) {
		for (int i = 0; i < 100; i++) {
			ideas[i] = rhs.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "(Brain destructor called)" << std::endl;
}

std::string const *Brain::getIdeas() const
{
	return ideas;
}
