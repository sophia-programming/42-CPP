#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (size_t i = 1; argv[i]; i++) {
			for (size_t j = 0; argv[i][j]; j++) {
				argv[i][j] = toupper(argv[i][j]);
			}
		}
		for (size_t i = 1; argv[i]; i++)
			std::cout << argv[i];
		std::cout << std::endl;
	}
}

