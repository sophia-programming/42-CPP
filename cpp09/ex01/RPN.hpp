#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <exception>
#include <sstream>
#include <stdexcept>
#include <cctype>

class RPN {
public:
	RPN();
	RPN(const RPN &to_copy);
	RPN &operator=(const RPN &to_copy);
	~RPN();

	static bool valid_expression(const std::string &expression);
	static int calculate(const std::string &expression);

	class NoResultException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class DivisionByZeroException : public std::exception {
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
