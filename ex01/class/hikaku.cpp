#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	// if (argc != 2) {
		// int arg = std::atoi(argv[1]);
		// if (0 <= arg < 10)
			// std::cout << "OK" << std::endl;
		// else
			// std::cout << "KO" << std::endl;
		// return 1;
	// }
	// else {
		// std::cout << "argument count is invalid." << std::endl;
		// return 0;
	int i = 42;
	if (0 <= i < 10) {
		std::cout << "OK";
	}
	return 1;;
}
