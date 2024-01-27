#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class AAnimal
{
public:
	AAnimal();
	AAnimal(std::string type);
	AAnimal(const AAnimal &rhs);
	virtual ~AAnimal();
	AAnimal &operator=(const AAnimal &rhs);

	const std::string &getType() const;
	void setType(const std::string &type);

	virtual void makeSound() const = 0;

protected:
	std::string type;
};

#endif
