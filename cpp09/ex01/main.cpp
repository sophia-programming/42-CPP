#include "RPN.hpp"

static int error_message(const std::string &message){
	std::cerr << RED << message << STOP << std::endl;
	return EXIT_FAILURE;
}

int main(int argc, char **argv){
	if (argc != 2)
		return error_message("Invalid number of arguments");

	if (!RPN::valid_expression(argv[1]))
		return error_message("Invalid expression");

	try {
		std::cout << RPN::calculate(argv[1]) << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << RED << e.what() << STOP << std::endl;
	}
	return EXIT_SUCCESS;
}
