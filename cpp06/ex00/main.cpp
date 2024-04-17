#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << GREEN << "Usage: ./convert [literal]" << STOP << std::endl;
		return 0;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
