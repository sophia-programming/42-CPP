#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <sstream>
#include <vector>
#include <list>
#include <time.h>

unsigned int ft_stou(const std::string &str);

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe &to_copy);
	PmergeMe &operator=(const PmergeMe &to_copy);
	~PmergeMe();

	void sortVector(int argc, char **argv);
	void sortList(int argc, char **argv);

class InvalidElementException : public std::exception {
public:
	virtual const char *what() const throw();
	};
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
