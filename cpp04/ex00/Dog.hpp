#ifndef CPP_DOG_HPP
#define CPP_DOG_HPP
#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	virtual ~Dog();
	Dog(const Animal &rhs);
	Dog &operator=(const Dog &rhs);

	virtual void makeSound() const;
};

#endif
