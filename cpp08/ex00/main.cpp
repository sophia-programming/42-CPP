#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

void testVectorInt() {
	std::cout << GREEN << "=== test1 ===" << STOP << std::endl;
	std::vector<int> v;
	for(size_t i = 0; i < 10; i++)
		v.push_back(i);

	std::cout << "v = ";
	for(std::vector<int>::iterator i = v.begin(), e = v.end(); i != e; i++){
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	try {
		std::cout << easyfind(v, 2) << std::endl;
		std::cout << easyfind(v, 42) << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << STOP << std::endl;
	}
}

void testVectorDouble() {
	std::cout << GREEN << "=== test2 ===" << STOP << std::endl;
	double array[] = {0.1, 1.1, 2.2, 3.3};
	int n = sizeof(array) / sizeof(array[0]);
	std::vector<double> vd(array, array + n);

	try {
		std::cout << "Found: " << easyfind(vd, 2.2) << std::endl;
		std::cout << "Found: " << easyfind(vd, 3.3) << std::endl;
		std::cout << "Found: " << easyfind(vd, 4.4) << std::endl;
	} catch (const std::exception &e) {
		std::cout << RED << e.what() << STOP << std::endl;
	}
}

void testEmptyVector() {
	std::cout << GREEN << "=== test3 ===" << STOP << std::endl;
	std::vector<int> empty;
	try {
		easyfind(empty, 10);
	} catch (const std::exception &e) {
		std::cout << RED << "Empty container test: " << e.what() << STOP << std::endl;
	}
}

void testListInt() {
	std::cout << GREEN << "=== test4 ===" << STOP << std::endl;
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(50);
	lst.push_back(70);
	lst.push_back(90);
	try {
		std::cout << easyfind(lst, 10) << std::endl;
		std::cout << easyfind(lst, 1000) << std::endl;
		std::cout << "Found 10 in list." << std::endl;
	} catch (const std::exception &e) {
		std::cout << RED << e.what() << STOP << std::endl;
	}
}

void testVectorChar() {
	std::cout << GREEN << "=== test5 ===" << STOP << std::endl;
	std::vector<char> vc;
	vc.push_back('a');
	vc.push_back('b');
	vc.push_back('c');
	try {
		std::cout << easyfind(vc, 'c') << std::endl;
		std::cout << easyfind(vc, 'z') << std::endl;
		std::cout << "Found 'c' in vector." << std::endl;
	} catch (const std::exception &e) {
		std::cout << RED << e.what() << STOP << std::endl;
	}
}

int main() {
	testVectorInt();
	testVectorDouble();
	testEmptyVector();
	testListInt();
	testVectorChar();
	return 0;
}
