#include "PmergeMe.hpp"

#define MICROSECOND 1000000

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &to_copy){
	*this = to_copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &to_copy){
	if (this != &to_copy){
		*this = to_copy;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

static void printVec(std::vector<unsigned int> &vec) {
	std::vector<unsigned int>::const_iterator itr;
	for (itr = vec.begin(); itr != vec.end(); itr++) {
		std::cout << *itr << " ";
	}
	std::cout << std::endl;
}

static std::vector<unsigned int> mergeVecs(std::vector<unsigned int> &left, std::vector<unsigned int> &right){
	std::vector<unsigned int> result;

	// Merge the two vectors until one of them is empty
	while (0 < left.size() && 0 < right.size()) {
		if (left.front() <= right.front()) {
			result.push_back(left.front());
			left.erase(left.begin());
		} else {
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}
	// Add the remaining elements of the left vector
	while (0 < left.size()) {
		result.push_back(left.front());
		left.erase(left.begin());
	}

	// Add the remaining elements of the right vector
	while (0 < right.size()) {
		result.push_back(right.front());
		right.erase(right.begin());
	}
	return result;
}

static std::vector<unsigned int> mergeInsertVec(std::vector<unsigned int> &vec){
	if (vec.size() <= 1) {
		return vec;
	}

	// Split the vector in two
	int middle = vec.size() / 2;
	std::vector<unsigned int> left(vec.begin(), vec.begin() + middle);
	std::vector<unsigned int> right(vec.begin() + middle, vec.end());

	// Recursively merge the two vectors
	left = mergeInsertVec(left);
	right = mergeInsertVec(right);

	// Merge the two vectors
	return mergeVecs(left, right);
}

void PmergeMe::sortVector(int argc, char **argv){
	std::vector<unsigned int> vec;
	for (int i = 1; i < argc; i++) {
		vec.push_back(ft_stou(argv[i]));
	}

	std::cout << GREEN << "<Vector>Before: " << STOP;
	printVec(vec);

	std::clock_t start = std::clock();
	vec = mergeInsertVec(vec);

	double time_taken
		= static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;

	std::cout << GREEN << "<Vector>After: " << STOP;
	printVec(vec);
	std::cout << "Time to process a range of " << argc - 1 << " elements "
	          << "with" << GREEN << " std::vector<unsigned int> : " << STOP << RED << time_taken << "  us" << STOP << std::endl;
}

static void printList(std::list<unsigned int> &lst){
	std::list<unsigned int>::const_iterator itr;
	for (itr = lst.begin(); itr != lst.end(); itr++) {
		std::cout << *itr << " ";
	}
	std::cout << std::endl;
}

static std::list<unsigned int> mergeLists(std::list<unsigned int> &left, std::list<unsigned int> &right){
	std::list<unsigned int> result;

	// Merge the two lists until one of them is empty
	while (0 < left.size() && 0 < right.size()) {
		if (left.front() <= right.front()) {
			result.push_back(left.front());
			left.erase(left.begin());
		} else {
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}

	// Add the remaining elements of the left list
	while (0 < left.size()) {
		result.push_back(left.front());
		left.erase(left.begin());
	}

	// Add the remaining elements of the right list
	while (0 < right.size()) {
		result.push_back(right.front());
		right.erase(right.begin());
	}
	return result;
}

static std::list<unsigned int> mergeInsertList(std::list<unsigned int> &lst){
	if (lst.size() <= 1) {
		return lst;
	}

	// Split the list in two
	int middle = lst.size() / 2;
	std::list<unsigned int> left;
	std::list<unsigned int> right;

	for (int i = 0; i < middle; i++) {
		left.push_back(lst.front());
		lst.pop_front();
	}
	right = lst;

	// Recursively merge the two lists
	left = mergeInsertList(left);
	right = mergeInsertList(right);

	// Merge the two lists
	return mergeLists(left, right);
}

void PmergeMe::sortList(int argc, char **argv){
	std::list<unsigned int> lst;
	for (int i = 1; i < argc; i++) {
		lst.push_back(ft_stou(argv[i]));
	}

	std::cout << YELLOW << "<list>Before: " << STOP;
	printList(lst);

	std::clock_t start = std::clock();
	lst = mergeInsertList(lst);

	double time_taken
		= static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;

	std::cout << YELLOW << "<list>After: " << STOP;
	printList(lst);
	std::cout << "Time to process a range of " << argc - 1 << " elements "
	          << "with" << YELLOW << " std::list<unsigned int> : " << STOP << RED << time_taken << "  us" << STOP << std::endl;
}

const char *PmergeMe::InvalidElementException::what() const throw() {
	return "Invalid element exception";
}
