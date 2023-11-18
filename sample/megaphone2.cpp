#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (std::size_t i = 0; argv[i]; i++) {
			char *p = argv[i];
			for (; *p; p++)
				*p = toupper(*p);
		}
		for (std::size_t i = 1; argv[i]; i++) {
			std::cout << argv[i];
		}
		std::cout << std::endl;
	}
	return 0;
}
