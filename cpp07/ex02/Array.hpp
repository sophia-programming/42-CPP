#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

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


template <class T>
class Array{
private:
	T *array_;
	unsigned int n_;

public:
	Array() : array_(NULL), n_(0) {
		std::cout << GREEN << "Default constructor called" << STOP << std::endl;
	}

	Array(unsigned int n) : array_(new T[n]), n_(n) {
		std::cout << GREEN << "Constructor called" << STOP << std::endl;
	}

	Array(const Array &src) : n_(src.n_) {
		array_ = new T[n_];
		for(unsigned int i = 0; i < n_; i++)
			array_[i] = src.array_[i];
		std::cout << GREEN << "Copy constructor called" << STOP << std::endl;
	}

	~Array() {
		std::cout << GREEN << "Destructor called" << STOP << std::endl;
		if (array_)
			delete[] array_;
		array_ = NULL;
	}

	Array &operator=(const Array &rhs) {
		if (this != &rhs) {
			delete[] array_;
			n_ = rhs.n_;
			array_ = new T[n_];
			for (unsigned int i = 0; i < n_; i++)
				array_[i] = rhs.array_[i];
		}
		std::cout << GREEN << "Assignment operator called" << STOP << std::endl;
		return *this;
	}

	T &operator[](unsigned int i) const {
		if (i >= n_ || !array_)
			throw std::out_of_range("Index out of range");
		return array_[i];
	}

	unsigned int size() const {
		return n_;
	}
};

#endif
