#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &rhs);
	virtual ~Animal();
	Animal &operator=(const Animal &rhs);

	const std::string &getType() const;
	void setType(const std::string &type);

	virtual void makeSound() const = 0;

protected:
	std::string type;
};

/* colors */
const char *const STOP = "\033[0m";
const char *const BOLD = "\033[1m";
const char *const BLACK = "\033[30m";
const char *const RED = "\033[31m";
const char *const GREEN = "\033[32m";
const char *const YELLOW = "\033[33m";
const char *const BLUE = "\033[34m";
const char *const MAGENTA = "\033[35m";
const char *const CYAN = "\033[36m";
const char *const WHITE = "\033[37m";
const char *const UNDERLINE =" \033[4m";

#endif
