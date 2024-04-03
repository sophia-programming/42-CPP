#include "easyfind.hpp"
#include <vector>

int main() {
	std::vector<int> v;
	for(size_t i = 0; i < 10; i++)
		v.push_back(i);

	std::cout << GREEN << "=== test1 ===" << STOP << std::endl;
	std::cout << "v = " ;
	for(std::vector<int>::iterator i = v.begin(), e = v.end(); i != e; i++){
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	try {
		easyfind(v, 0);
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << STOP << std::endl;
	}

	std::cout << GREEN << "=== test2 ===" << STOP << std::endl;
	try{
		easyfind(v, 42);
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << STOP << std::endl;
	}
	return EXIT_SUCCESS;
}


