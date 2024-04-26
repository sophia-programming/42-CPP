#include "ScalarConverter.hpp"

int	main(int argc, char *argv[]) {
	if (argc != 2 || !argv[0] || !argv[1]) {
		std::cerr << RED << "Usage: " << argv[0] << " <scalar>" << STOP << std::endl;
		return (1);
	}
	std::string str = argv[1];
	ScalarConverter::convert(str);
};
