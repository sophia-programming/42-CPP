#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array{
private:
	T *array;
	unsigned int n;

public:
	Array() : n(0) {
		array = new T[n];
	}

	Array(unsigned int n) : n(n) {
		array = new T[n];
	}

	Array(const Array &src) : n(src.n) {
		array = new T[n];
		for(unsigned int i = 0; i < n; i++)
			array[i] = src.array[i];
	}

	~Array() {
		delete[] array;
	}

	Array &operator=(const Array &rhs) {
		if (this != &rhs){
			delete[] array;
			n = rhs.n;
			array = new T[n];
			for(unsigned int i = 0; i < n; i++)
				array[i] = rhs.array[i];
		}
	}

	T &operator[](unsigned int i) const {
		if (n <= i)
			throw std::exception();
		return array[i];
	}

	unsigned int size() const {
		return n;
	}
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
