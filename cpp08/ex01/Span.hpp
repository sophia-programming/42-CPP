#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span{
public:
	Span(unsigned int N);
	Span(const Span &to_copy);
	Span &operator=(const Span &to_copy);
	~Span();

	void addNumber(int n);
	void addRandomNumbers(unsigned int n);
	int shortestSpan();
	int longestSpan();

	void printStorage();

	class NotEnoughNumbersException : public std::exception {
		public:
		const char *what() const throw();
	};

	class StorageFullException : public std::exception {
		public:
		const char *what() const throw();
	};

private:
	unsigned int max_size;
	std::vector<int> storage;
	Span();
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
