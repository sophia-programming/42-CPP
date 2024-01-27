#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
	Cat();
	virtual ~Cat();
	Cat(const Cat &rhs);
	Cat &operator=(const Cat &rhs);

	virtual void makeSound() const;
	Brain const *getBrain() const;

private:
	Brain *brain;
};

#endif
