#ifndef CPP_WRONGCAT_HPP
#define CPP_WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	WrongCat(const WrongCat &rhs);
	~WrongCat();
	WrongCat &operator=(const WrongCat &rhs);

	void makeSound() const;
};

#endif
