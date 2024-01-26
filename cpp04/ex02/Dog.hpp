#ifndef CPP_DOG_HPP
#define CPP_DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"
#include "AAnimal.hpp"

class Dog : public AAnimal {
public:
	Dog();
	virtual ~Dog();
	Dog(const Dog &rhs);
	Dog &operator=(const Dog &rhs);

	virtual void makeSound() const;
	Brain const *getBrain() const;

private:
	Brain *brain;
};

#endif
