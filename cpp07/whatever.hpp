#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template< typename T >
void swap(T &a, T &b ) {
	T tmp = a;
	a = b;
	b = tmp;
}

template< typename T >
T min(T a, T b) {
	if (a == b)
		return b;
	return (a > b ? b : a);
}

template< typename T >
T max(T a, T b) {
	if (a == b)
		return b;
	return (a > b ? a : b);
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
