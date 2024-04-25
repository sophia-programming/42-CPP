#include "iter.hpp"

int main() {
	std::cout << GREEN << "======intArray:=====" << STOP << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	iter(intArray, 5, print);

	std::cout << GREEN << "======floatArray:=====" << STOP << std::endl;
	float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	iter(floatArray, 5, print);

	std::cout << GREEN << "=====strArray:=====" << STOP << std::endl;
	std::string strArray[] = {"one", "two", "three", "four", "five"};
	iter(strArray, 3, print);
	return 0;
}
