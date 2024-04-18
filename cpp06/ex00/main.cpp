#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cerr << GREEN << "Usage: " << argv[0] << " <value1>" << STOP << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; i++) {
		ScalarConverter::convert(argv[i]);
	}
	return 0;
}
