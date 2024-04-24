#include "Span.hpp"

Span::Span(unsigned int N) : max_size_(N) , storage_(0) {
	std::cout << YELLOW << "Constructor called" << STOP << std::endl;
}

Span::Span(const Span &to_copy) {
	std::cout << YELLOW << "Copy constructor called" << STOP << std::endl;
	*this = to_copy;
}

Span &Span::operator=(const Span &to_copy) {
	std::cout << YELLOW << "Assignation operator called" << STOP << std::endl;
	if (this != &to_copy)
	{
		this->max_size_ = to_copy.max_size_;
		this->storage_ = to_copy.storage_;
	}
	return *this;
}

Span::~Span() {
	std::cout << YELLOW << "Destructor called" << STOP << std::endl;
}

void Span::addNumber(int n) {
	if (this->storage_.size() == this->max_size_)
		throw StorageFullException();
	this->storage_.push_back(n);
}

void Span::addRandomNumbers(unsigned int n) {
	srand(time(NULL));
	try {
		for (unsigned int i = 0; i < n; i++)
			this->addNumber(rand());
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << STOP << std::endl;
	}
}

unsigned int Span::shortestSpan() {
	std::vector<int> v = this->storage_;

	if (v.size() < 2)
		throw Span::NotEnoughNumbersException();
	std::sort(v.begin(), v.end());

	int shortest_gap = v.at(1) - v.at(0);
	std::vector<int>::iterator i;
	for(i = v.begin(); i != v.end() - 1; i++){
		if ((*(i + 1) - *i) < shortest_gap)
			shortest_gap = (*(i + 1) - *i);
	}
	return shortest_gap;
}

unsigned int Span::longestSpan() {
	std::vector<int> v = this->storage_;

	if (v.size() < 2)
		throw Span::NotEnoughNumbersException();

	int min = *std::min_element(v.begin(), v.end());
	int max = *std::max_element(v.begin(), v.end());

	return abs(max - min);
}

void Span::printStorage() {
	std::vector<int> v = this->storage_;
	std::vector<int>::iterator i;

	std::cout << "storage_ = ";
	for(i = v.begin(); i != v.end(); i++){
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

char const *Span::StorageFullException::what() const throw() {
	return "Storage is full.";
}

char const *Span::NotEnoughNumbersException::what() const throw() {
	return "Not enough numbers to calculate span.";
}
