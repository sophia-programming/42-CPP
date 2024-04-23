#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << GREEN << "Usage: " << argv[0] << " <value>" << STOP << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; i++) {
		if (argv[1][0] == '.')
			std::cout << RED << "Invalid input" << STOP << std::endl;
		else
			ScalarConverter::convert(argv[i]);
	}
	return 0;
}
