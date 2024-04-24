#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class EasyFindException : public std::exception {
	public:
	const char *what() const throw() {
		return "Element not found.";
	}
};

template <typename T>
const typename T::value_type &easyfind(const T &container, int toFind) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw EasyFindException();
	else
		return *it;
}

template <typename T, typename U>
const typename T::value_type &easyfind(const T &container, U toFind) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw EasyFindException();
	else
		return *it;
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
