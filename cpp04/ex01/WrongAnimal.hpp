#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animal.hpp"
#include <iostream>

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &rhs);
	~WrongAnimal();
	WrongAnimal &operator=(const WrongAnimal &rhs);

	const std::string &getType() const;
	void makeSound() const;
protected:
	std::string type;
};

#endif
