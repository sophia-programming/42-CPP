#include <iostream>
#include "ScalarConverter.hpp"

int main() {
	std::string literals[] = {"0", "nan", "42.0f", "+inff", "-inff", "2147483647", "nanf", "+inf", "-inf", "'a'", "42", "-2147483648"};
	int numLiterals = sizeof(literals) / sizeof(std::string);

	for (int i = 0; i < numLiterals; i++) {
		std::cout << YELLOW << "====================" << STOP << std::endl;
		std::cout << "./convert " << literals[i] << std::endl;
		ScalarConverter::convert(literals[i]);
		std::cout << std::endl;
	}

	return 0;
}
