#include "Conversion.hpp"

int main(int argc, char **argv) {
	try {
		if (argc == 1) {
			std::cout << RED << "Invalid argument count!" << STOP << std::endl;
			return 1;
		}
		std::string arg(argv[1]);
		convert(arg);
	} catch (...) {
		std::cout << RED << "Unable to cast : Large input" << STOP << std::endl;
 	}
	return 0;
}
