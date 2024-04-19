#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << GREEN << "Usage: " << argv[0] << " <value>" << STOP << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; i++) {
		ScalarConverter::convert(argv[i]);
	}
	return 0;
}
