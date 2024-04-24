#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*f)(T const &)) {
	if (!array || !f)
		return ;
	for (size_t i = 0; i < length; i++) {
		f(array[i]);
	}
}

template <typename T1, typename T2>
void iter(T1 *array1, T2 *array2, size_t length, void (*f)(T1 const &, T2 const &)) {
	if (!array1 || !array2 || !f)
		return ;
	for (size_t i = 0; i < length; i++) {
		f(array1[i], array2[i]);
	}
}

template <typename T>
void print(T const &x) {
	std::cout << x << std::endl;
}

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
