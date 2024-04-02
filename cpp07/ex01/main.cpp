#include "iter.hpp"

int main() {
	std::cout << GREEN << "======intArray:=====" << STOP << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	iter(intArray, 5, print);

	std::cout << GREEN << "=====strArray:=====" << STOP << std::endl;
	std::string strArray[] = {"one", "two", "three", "four", "five"};
	iter(strArray, 5, print);
	return 0;
}
