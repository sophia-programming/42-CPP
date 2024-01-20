//derived class should be virtual destructor

#ifndef CPP_CAT_HPP
#define CPP_CAT_HPP
#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat();
	virtual ~Cat();
	Cat(const Animal &rhs);
	Cat &operator=(const Cat &rhs);

	virtual void makeSound() const;
};

#endif
