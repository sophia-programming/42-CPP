#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include <sstream>

class Brain {
public:
	Brain();
	Brain(std::string type);
	virtual ~Brain();
	Brain(const Brain &rhs);
	Brain &operator=(const Brain &rhs);

	const std::string *getIdeas() const;

private:
	std::string ideas[100];
};

#endif
