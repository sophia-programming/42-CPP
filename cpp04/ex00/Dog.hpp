#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	virtual ~Dog();
	Dog(const Dog &rhs);
	Dog &operator=(const Dog &rhs);

	virtual void makeSound() const;
};

#endif
