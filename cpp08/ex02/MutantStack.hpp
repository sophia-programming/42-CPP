#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

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

#include <iostream>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	MutantStack();
	MutantStack(const MutantStack &to_copy);
	MutantStack &operator=(const MutantStack &to_copy);
	~MutantStack();

	iterator begin();
	iterator end();
};

template <typename T>
MutantStack<T>::MutantStack() {
	std::cout << BLUE << "MutantStack default constructor" << STOP << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &to_copy) {
	std::cout << BLUE << "MutantStack copy constructor" << STOP << std::endl;
	*this = to_copy;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &to_copy) {
	std::cout << BLUE << "MutantStack assignation operator" << STOP << std::endl;
	if (this != &to_copy){
		this->c = to_copy.c;
	}
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {
	std::cout << BLUE << "MutantStack destructor" << STOP << std::endl;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}

#endif
